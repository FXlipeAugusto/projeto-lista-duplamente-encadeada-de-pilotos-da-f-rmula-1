#include "LogicaPilotos.h"  
#include "arquivoPilotos.h"
#include "extensaoMenu.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    TLLSE lista;
    inicializarLLSE(&lista);
    
    int resposta;
    do {
        printf("\n\n\n");
        printf("**********************************\n");
        printf("**   BOAS VINDAS À FORMULA 1!  **\n");
        printf("**********************************\n");
        printf("Digite o número do que você deseja fazer:\n");
        printf("1 - Carregar o arquivo.\n");
        printf("2 - Listar os dados da lista\n");
        printf("3 - Inserir no início da lista\n");
        printf("4 - Acessar o início da lista\n");
        printf("5 - Retirar do início da lista\n");
        printf("6 - Inserir no fim da lista\n");
        printf("7 - Acessar o fim da lista\n");
        printf("8 - Retirar do fim da lista\n");
        printf("9 - Sair\n");
        scanf("%d", &resposta);
        
        while((resposta < 1) || (resposta > 9)) {
            printf("Favor, digitar um número válido!\n");
            scanf("%d", &resposta);
        }
        
        switch(resposta) 
        //switch é um comando de fluxo que permite a execução de diferentes blocos baseado no valor da 
        //espressao (parametro)
        {
            case 1:
                system("cls");
                //System("cls") é o comando usado para limpar as mensagens anteriores da tela.

                carregarDadosNaLista(&lista, "DadosDosPilotosF1.csv");
                break;

            case 2: 
                system("cls");
                char* dados = mostrarLLSE(&lista);
                printf("%s\n", dados);
                free(dados);
                break;
            
            case 3: 
                system("cls");
                coletarDadosinserirINICIO(&lista);
                break;
            

            case 4:
                system("cls");
                //Obs: a função acessarInicioLLSE, dentro do acessoAoInicio,
                //já verifica por conta própria se a lista não está vazia.
                //Sendo assim, não precisa verificar aqui.
                acessoAoInicio(&lista);
                break;
            
            case 5:
                system("cls");

                if(estaVazia(&lista)){
                    printf("A lista está vazia!\n");
                }
                else if(retirarInicioLLSE(&lista)){
                    printf("Piloto retirado do início da lista!\n");
                }
                else printf("Não foi possível retirar piloto do início da lista!\n");

                break;
            

            case 6:
                system("cls");
                coletarDadosinserirFIM(&lista);
                break;
            

            case 7:
                system("cls");
                //Obs: a função acessarFimLLSE já verifica por conta própria se a lista não está vazia.
                //Sendo assim, não precisa verificar aqui.
                acessoAoFim(&lista);
                break;
            
            
            case 8:
                system("cls");

                if(estaVazia(&lista)){
                    printf("A lista está vazia!\n");
                }
                else if(retirarFimLLSE(&lista)){
                    printf("Piloto retirado do final da lista!\n");
                }
                else printf("Não foi possível retirar piloto do final da lista!\n");

                break;
            
            
            case 9:
                system("cls");
                printf("Saindo...\n");
                break;
                
            default:
                //default é executado quando nenhum case corresponde à expressão
                printf("Opção inválida.\n");
        }
    } while(resposta != 9);
    
    liberarLLSE(&lista);
    return 0;
    
}