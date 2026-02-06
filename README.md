# LISTA DUPLAMENTE ENCADEADA DE PILOTOS DA FÓRMULA 1
    este é um programa pesnado para listagem, inserção, alteração e remoção de pilotos. Os dados são estrurados em listas duplamente encadeadas e armazenados em arquivo .csv.
---

## Sobre


* O objetivo deste programa é, antes de tudo, ser um treino e estudo sobre a linguagem C e suas estruturas de dados.
  Neste projeto, usei de lista duplamente encadeada para acessar dados de pilotos, organizados por nome, equipe, pontuação e número.

---

##  Funcionalidades

* Carregar o arquivo
* Listar os dados da lista
* Inserir no início da lista
* Acessar o início da lista
* Retirar do início da lista
* Inserir no fim da lista
* Acessar o fim da lista
* Retirar do fim da lista

---

##  Requisitos

Para compilar e executar este programa, você precisa de:

* Compilador C (gcc ou clang)
* Sistema operacional compatível (Linux / Windows / macOS)



---

##  Estrutura do projeto

* DadosDosPilotos.CSV 
    arquivo base que contém as informações dos pilotos (matricula; nome; país; idade; equipe; país; número)
* arquivoPilotos.h
    responsável pela manipulação do arquivo .csv, estraindo os dados e guardando-os nas estruturas de dados
* pilotosMain.c
    responsável pela interface em que o usuário irá interagir, disponibilizando o menu das funções do programa
* extensaoMenu.h
    menu secundário para inserção de novos pilotos. Sua função é coletar os dados dos pilotos fornecidos pelo usuário.
*logicaPilotos.h
    define as structs do piloto, seus nós e traz as funções que irão envover a lista.



##  Autor

Felipe Augusto Diniz Borges
email: fellippeauggusto720@gmail.com
