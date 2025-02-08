/* Daniela Souza Costa 
Matrícula: 20242005840
Beatriz Piedade Rodrigues
Matrícula: 20242005699 */

#include "fila.h"

fila* criaFila(){
    fila *f = (fila*)malloc(sizeof(fila));
    f->inicio == NULL;
    f->fim == NULL;
    return f;
}

int testeVazia(fila *fila){
    if(fila->inicio == NULL && fila->fim == NULL ) return 1;
    else return 0; 
}

void enfileirar(fila *fila, dados d){
    FILE *arquivo = fopen("conteudo.txt", "a");
    dados *novo = (dados *)malloc(sizeof(dados));

    strcmp(novo->nome, d.nome);
    novo->idade = d.idade;
    strcmp(novo->descricao, d.descricao);
    strcmp(novo->extra1, d.extra1);
    strcmp(novo->extra2, d.extra2);

    if(testeVazia(fila)){
        fila->fim = fila->inicio = novo;
    }
    else{
        fila->fim->prox = novo;
        fila->fim = novo;
    }

    fprintf(arquivo, "%s %d %s %s %s\n", novo->nome, novo->idade, novo->descricao, novo->extra1, novo->extra2);
}

void desempilhar(){

}
