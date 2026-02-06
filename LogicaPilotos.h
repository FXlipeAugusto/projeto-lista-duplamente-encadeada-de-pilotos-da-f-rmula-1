#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Struct do tipo TPiloto - Tipo piloto.
typedef struct Piloto {
    int matricula;  
    char nome[50];
    char pais[30];
    int idade;         
    char equipe[30];
    char motor[30];
    int pontos;
}TPiloto;

//Struct de tipo Nó
typedef struct TNo{
    TPiloto Piloto;
    struct TNo *proximo;
}TNo;

//Struct do tipo TLLSE - Tipo Lista Linear Simplesmente Encadeada
typedef struct TLLSE{
    int tamanho;
    struct TNo* inicio;
}TLLSE;

//Essa função cria o nó da lista
TNo* criarNo(TPiloto * piloto){
    TNo *no = (TNo *)malloc(sizeof(TNo));
    //sizeof retorna tamanho em bytes de TNo
    if (no == NULL) return NULL;

    no->Piloto = *piloto;
    no->proximo = NULL;
    return no;
}

//Essa função inicializa a Lista Linear Simplesmente Encadeada
void inicializarLLSE(TLLSE *const lista){
    lista->inicio = NULL;
    lista->tamanho = 0;
}
//Verifica se a lista está vazia
int estaVazia(TLLSE const*const lista){
    return(!lista->tamanho);
}

//Libera a lista e sua memória
void liberarLLSE(TLLSE *const lista){
    TNo*pAux = lista->inicio;
    while(pAux != NULL){
        TNo *No = pAux;
        pAux = pAux->proximo;
        free(No);
    }
    lista->inicio = NULL;  
    lista->tamanho = 0;     
}

//Insere elementos no início da lista
int inserirInicioLLSE(TPiloto *const piloto, TLLSE *const lista){
    TNo* no = criarNo(piloto);
    if (no == NULL) return 0;
    TNo *pAux = no;
    pAux->proximo = lista->inicio;
    lista->inicio = pAux;
    lista->tamanho++;
    return 1;
}

//Insere elementos no fim da lista 
int inserirFimLLSE(TPiloto *const piloto, TLLSE *const lista){
    TNo* no = criarNo(piloto);
    if (no == NULL) return 0;
    TNo *pAux = no;

    if(estaVazia(lista)){
        lista->inicio = pAux;
        lista->tamanho++;
        return 1;
    }
    
    TNo *PA = lista->inicio;

    while(PA->proximo != NULL){
        PA = PA->proximo;
    }

    PA->proximo = pAux;
    lista->tamanho++;
    return 1;
}

//A função retira o elemento do início da lista
int retirarInicioLLSE(TLLSE *const lista){
    if(estaVazia(lista)){
        printf("Lista vazia!\n");
        return 0;
    }
    TNo *pAux = lista->inicio;
    lista->inicio = pAux->proximo;  // Move o ponteiro para o próximo nó
    free(pAux);
    lista->tamanho--;
    return 1;
}

//A função retira o elemento do fim da lista 
int retirarFimLLSE(TLLSE *const lista){
    if(estaVazia(lista)){
        printf("Lista vazia!\n");
        return 0;
    }

    if(lista->tamanho == 1){
        free(lista->inicio);
        lista->inicio = NULL;
        lista->tamanho = 0;
        return 1;
    }
    TNo* pAux = lista->inicio;
    while(pAux->proximo->proximo != NULL){
        pAux = pAux->proximo;
    }
    free(pAux->proximo);
    pAux->proximo = NULL;
    lista->tamanho--;
    return 1;
}



//Essa função acessa o início da lista
TPiloto * acessarInicioLLSE(TLLSE const*const lista){
    if(estaVazia(lista)){
        printf("Lista vazia!\n");
        return NULL;
    }
    return &(lista->inicio->Piloto);
}

//Essa função acessa o fim da lista  
TPiloto * acessarFimLLSE(TLLSE const*const lista){
    if(estaVazia(lista)){
        printf("Lista vazia!\n");
        return NULL;
    }
    TNo*pAux = lista->inicio;
    while(pAux->proximo != NULL){
        pAux = pAux->proximo;
    }
    return &(pAux->Piloto);
}

//Mostra a lista completa.
char* mostrarLLSE(TLLSE const* const lista) {
    char* buffer = (char*)malloc(sizeof(char) * 4092); 

    //Buffers usam tamanhos de potência de 2 por questões de redução de fragmentação,
    //Deixando o código melhor otimizado. Os blocos de memória trabalham com potência
    //de base 2.

    if (buffer == NULL) return NULL;

    if (estaVazia(lista)) {
        sprintf(buffer, "LLSE = {∅}");
        return buffer;
    }

    //sprintf: Ao invés de mostrar dados na tela, ela escreve esses dados formatados
    //numa string, nesse caso, o buffer.
    sprintf(buffer, "lista = {\n");
    TNo* noAtual = lista->inicio;

    while (noAtual != NULL) {
        char aux[200];
        sprintf(aux, " Matricula: %d, Nome: %s, País: %s, Idade: %d, Equipe: %s, Motor: %s, Pontos: %d\n",
                noAtual->Piloto.matricula, noAtual->Piloto.nome, noAtual->Piloto.pais,
                noAtual->Piloto.idade, noAtual->Piloto.equipe, noAtual->Piloto.motor,
                noAtual->Piloto.pontos);
        strcat(buffer, aux);
        noAtual = noAtual->proximo;
    }
    strcat(buffer, "}");

    return buffer;
}
