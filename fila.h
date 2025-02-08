/* Daniela Souza Costa 
Matrícula: 20242005840
Beatriz Piedade Rodrigues
Matrícula: 20242005699 */

#ifndef FILA_H
#define FILA_H

#include <stdio.h> 
#include <stdlib.h>

typedef struct dados_{
    char nome[100];
    int idade;
    char descricao[1000];
    char extra1[50];
    char extra2;
    struct dados_ *prox;

} dados;

typedef struct{
    dados *inicio;
    dados *fim;
} fila;

void criaFila(fila *cria);
int testeVazia(fila *fila);
void enfileirar(fila *fila, dados d);
void desenfileirar();
void desalocar();
void imprimir();
void lerArquivo();
void salvarArquivo();

#endif
