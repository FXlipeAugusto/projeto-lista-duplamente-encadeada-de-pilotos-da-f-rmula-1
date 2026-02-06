#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void carregarDadosNaLista(TLLSE * const lista, const char* arquivo) {
    FILE *file = fopen(arquivo, "r");
    //fopen(): abre o arquivo
    //primeiro parametro: nome do arquivo a ser aberto
    //segundo parametro: modo de abertura do arquivo (r = read, a = add, w = write)
    //retorna ponteiro do tipo file ou NULL em caso de erro

    if (file == NULL) {
        printf("Erro ao abrir o arquivo %s\n\n\n", arquivo);
        return;
    }
    else printf("Arquivo carregado com sucesso. \n");
    
    char linha[256];

    while (fgets(linha, sizeof(linha), file)) {
        //fgets():le uma linha de texto (até encontrar um \n) e a armazena em um buffer
        // primeiro parametro: ponteiro para o array em que a string lida será armazenada
        // segundo parametro: numero maximo de caracteres a serem lidos (já incluso \0)
        // terceiro parametro: onde será lida a string. file = arquivo, stdin = entrada do usuario
        //retorna ponteiro para o buffer
        // em caso de erro ou fim do arquivo, retorna NULL
        //Em C, o NULL é interpretado como falso (0). Logo, uma função que retorna NULL, pode
        //ser usada como parametro para um while.

        TPiloto *piloto = (TPiloto *)malloc(sizeof(TPiloto)); 

        
        char *token = strtok(linha, ";");
        //strtok(): essa função divide a string em tokens, com base no delimitador (;)
        //primeiro parametro: a string de origem de onde serão extraido os tokens
        //segundo parametro: o caractere delimitador dos tokens.
        //ATENÇÃO! a string de origem só deve ser chamada uma vez. Nas demais é null para continuar a tokenizacao.
        //retorna um ponteiro char para o token ou NULL em caso de fim dos tokens

        if (token) piloto->matricula = atoi(token);
        //atoi: converte uma string em numero (int)
        //parametro: ponteiro para a string (numero)
        // retorna o valor convertido (int)
        // em caso de erro, retorna 0.

        
        token = strtok(NULL, ";");
        if (token) strcpy(piloto->nome, token); 
        // strcpy(): copia uma string de origem para uma string de destino
        // primeiro parametro: ponteiro para a string de destino
        // segundo parametro: ponteiro para a string de origem (a que será copiada)
        // retorna um ponteiro para a string de destino 
        
        token = strtok(NULL, ";");
        if (token) strcpy(piloto->pais, token);
        // usa-se if token, pois quando o strtok() chega ao fim dos tokens, ele retorna NULL
        //como dito antes, C interpreta NULL como sendo falso.
        
        token = strtok(NULL, ";");
        if (token) piloto->idade = atoi(token);  
        
        token = strtok(NULL, ";");
        if (token) strcpy(piloto->equipe, token);
        
        token = strtok(NULL, ";");
        if (token) strcpy(piloto->motor, token);
        
        token = strtok(NULL, "\n");
        if (token) piloto->pontos = atoi(token); 
        
        inserirFimLLSE(piloto, lista); 
    }
    
    fclose(file);
    //fecha um arquivo previamente aberto.
}