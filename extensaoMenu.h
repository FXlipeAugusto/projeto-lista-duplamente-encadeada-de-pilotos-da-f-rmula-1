#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//Módulo que dispôe um menu para coletar os dados do piloto novo a ser listado no inicio
void coletarDadosinserirINICIO(TLLSE *const lista){
    TPiloto novoPiloto;
                printf("Digite a matrícula: ");
                scanf("%d", &novoPiloto.matricula);
                getchar(); 
                //getchar(): lê um único caractere de entrada do usuario.
                //aplicacao: ler o \n deixado pelo scanf e limpar o buffer de entrada 
                //retorna um int com o número da tabela ascii do caractere.
    
                printf("Digite o nome: ");
                fgets(novoPiloto.nome, sizeof(novoPiloto.nome), stdin);
                //fgets():le uma linha de texto (até encontrar um \n) e a armazena em um buffer
                // primeiro parametro: ponteiro para o array em que a string lida será armazenada
                // segundo parametro: numero maximo de caracteres a serem lidos (já incluso \0)
                // terceiro parametro: onde será lida a string. file = arquivo, stdin = entrada do usuario
                //retorna ponteiro para o buffer
                // em caso de erro ou fim do arquivo, retorna NULL
                //Em C, o NULL é interpretado como falso (0). Logo, uma função que retorna NULL, pode
                //ser usada como parametro para um while.

                novoPiloto.nome[strcspn(novoPiloto.nome, "\n")] = '\0'; 
                //strcspn: em uma string 1, retorna a posição do primeiro caractere da string2 que se deseja buscar
                //primeiro parametro: o ponteiro para a string 1
                //segundo parametro: a string 2 que se deseja encontrar na string 1
                //retorna um int com a posição do primeiro caractere da string 2
                //caso não encontrado nada, retorna o comprimento total da string 1.
    
                printf("Digite o país: ");
                fgets(novoPiloto.pais, sizeof(novoPiloto.pais), stdin);
                novoPiloto.pais[strcspn(novoPiloto.pais, "\n")] = '\0';
    
                printf("Digite a idade: ");
                scanf("%d", &novoPiloto.idade);
                getchar();
                
    
                printf("Digite a equipe: ");
                fgets(novoPiloto.equipe, sizeof(novoPiloto.equipe), stdin);
                novoPiloto.equipe[strcspn(novoPiloto.equipe, "\n")] = '\0';
    
                printf("Digite a fabricante do motor: ");
                fgets(novoPiloto.motor, sizeof(novoPiloto.motor), stdin);
                novoPiloto.motor[strcspn(novoPiloto.motor, "\n")] = '\0';
    
                printf("Digite a pontuação do piloto: ");
                scanf("%d", &novoPiloto.pontos);
                getchar();
    
                if(inserirInicioLLSE(&novoPiloto, lista)) {
                    printf("\nPiloto inserido com sucesso no início da lista!\n\n");
                } 
                else {
                    printf("Erro ao inserir piloto.\n");
                }
}

//Módulo que dispôe um menu para coletar os dados do piloto novo a ser listado no final
void coletarDadosinserirFIM(TLLSE *const lista){
    TPiloto novoPiloto;
                printf("Digite a matrícula: ");
                scanf("%d", &novoPiloto.matricula);
                getchar(); //O getchar() lê um buffer de entrada (uma entrada do usuário), no caso, o \n (enter) que o usuário aplicou
                           //Serve para limpar o buffer do teclado, ou seja, tira caracteres antigo que podem estar armazenados.
    
                printf("Digite o nome: ");
                fgets(novoPiloto.nome, sizeof(novoPiloto.nome), stdin);
                novoPiloto.nome[strcspn(novoPiloto.nome, "\n")] = '\0'; 
                //Aqui não é preciso o getchar(), pois o strcspn já retorna a posição do \n e lhe é atribuido \0.
    
                printf("Digite o país: ");
                fgets(novoPiloto.pais, sizeof(novoPiloto.pais), stdin);
                novoPiloto.pais[strcspn(novoPiloto.pais, "\n")] = '\0';
                //Aqui não é preciso o getchar(), pois o strcspn já retorna a posição do \n e lhe é atribuido \0.

    
                printf("Digite a idade: ");
                scanf("%d", &novoPiloto.idade);
                getchar();
                //Aqui já é preciso, pois scanf() deixa o \n do usuário no buffer de entrada.
                
    
                printf("Digite a equipe: ");
                fgets(novoPiloto.equipe, sizeof(novoPiloto.equipe), stdin);
                novoPiloto.equipe[strcspn(novoPiloto.equipe, "\n")] = '\0';
    
                printf("Digite a fabricante do motor: ");
                fgets(novoPiloto.motor, sizeof(novoPiloto.motor), stdin);
                novoPiloto.motor[strcspn(novoPiloto.motor, "\n")] = '\0';
    
                printf("Digite a pontuação do piloto: ");
                scanf("%d", &novoPiloto.pontos);
                getchar();
    
                if(inserirFimLLSE(&novoPiloto, lista)) {
                    //InserirFimLLSE é uma função int. Logo, retorna 0 ou diferente de 0
                    printf("\nPiloto inserido com sucesso no fim da lista!\n\n");
                } 
                else {
                    printf("Erro ao inserir piloto.\n");
                }
}

//este módulo mostra os dados do AcessarInicioLLSE da lista
void acessoAoInicio(TLLSE const * const lista){
    TPiloto * piloto = acessarInicioLLSE(lista);
                if(piloto != NULL){
                    printf("Piloto no início da lista:\n");
                    printf("Matrícula: %d\n", piloto->matricula);
                    printf("Nome: %s\n", piloto->nome);
                    printf("País: %s\n", piloto->pais);
                    printf("Idade: %d\n", piloto->idade);
                    printf("Equipe: %s\n", piloto->equipe);
                    printf("Motor: %s\n", piloto->motor);
                    printf("Pontuação: %d\n", piloto->pontos);
                }

}

//este módulo mostra os dados do AcessarFimLLSE da lista
void acessoAoFim(TLLSE const * const lista){
    TPiloto * piloto = acessarFimLLSE(lista);
                if(piloto != NULL){
                    printf("Piloto no fim da lista:\n");
                    printf("Matrícula: %d\n", piloto->matricula);
                    printf("Nome: %s\n", piloto->nome);
                    printf("País: %s\n", piloto->pais);
                    printf("Idade: %d\n", piloto->idade);
                    printf("Equipe: %s\n", piloto->equipe);
                    printf("Motor: %s\n", piloto->motor);
                    printf("Pontuação: %d\n", piloto->pontos);
                }

}