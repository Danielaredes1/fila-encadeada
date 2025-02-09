/* Daniela Souza Costa 
Matrícula: 20242005840
Beatriz Piedade Rodrigues
Matrícula: 20242005699 */

#ifndef FILA_H
#define FILA_H

    #include <stdio.h> 
    #include <stdlib.h>
    #include <string.h>

    typedef struct dados_{
        char nome[100];
        char idade[10];
        char descricao[100];
        char extra1[50];
        char extra2[50];
        struct dados_ *prox;

    } dados;

    typedef struct No {
        dados dado;
        struct No *prox;
    } no;
    
    typedef struct{
        no *inicio;
        no *fim;
    } fila;

    fila* criaFila();
    int testeVazia(fila *fila);
    void enfileirar(fila *fila, dados d);
    void desenfileirar(fila *fila);
    void desalocar(fila *fila);
    void imprimir();
    void lerArquivo();
    void salvarArquivo();

#endif
