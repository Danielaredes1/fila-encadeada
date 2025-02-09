/* Daniela Souza Costa 
Matrícula: 20242005840
Beatriz Piedade Rodrigues
Matrícula: 20242005699 */

#include "fila.h"

fila* criaFila(){
    fila *f = (fila*)malloc(sizeof(fila));
    f->inicio = NULL;
    f->fim = NULL;
    return f;
}

int testeVazia(fila *fila){
    if(fila->inicio == NULL && fila->fim == NULL ) return 1;
    else return 0; 
}

void enfileirar(fila *fila, dados d){
    FILE *arquivo = fopen("conteudo.txt", "a");
    if(arquivo == NULL) exit(1);

    no *novo = (no *)malloc(sizeof(no));
    if(novo == NULL){
        fclose(arquivo);
        exit(1);
    }

    novo->dado = d;
    novo->prox = NULL;

    if(testeVazia(fila)){
        fila->fim = fila->inicio = novo;
    }
    else{
        fila->fim->prox = novo;
        fila->fim = novo;
    }

    fprintf(arquivo, "%s %s %s %s %s\n", d.nome, d.idade, d.descricao, d.extra1, d.extra2);
    fclose(arquivo);
}

void desenfileirar(fila *fila){
    FILE *arquivo = fopen("conteudo.txt", "r");
    if(arquivo == NULL) exit(1);

    FILE *arqtemp = fopen("temp.txt", "w");
    if(arqtemp == NULL) exit(1);

    if(testeVazia(fila)) {
        printf("A fila já está vazia");
        exit(1);
    }

    no *temp = fila->inicio;
    fila->inicio = fila->inicio->prox;

    if(fila->inicio == NULL){
        fila->fim = NULL;
    }
    
    free(temp);
    
    char linha[400];
    int primeira = 1;

    while(fgets(linha, 400, arquivo) != NULL){
        if(primeira){
            primeira = 0;
            continue;
        }

        fputs(linha, arqtemp);
    }

    fclose(arquivo);
    fclose(arqtemp);

    remove("conteudo.txt");
    rename("temp.txt", "conteudo.txt");
}

void desalocar(fila *fila){
    FILE *arquivo = fopen("conteudo.txt", "r+");
    if(arquivo != NULL)  fclose(arquivo);

    while(fila->inicio != NULL){
        no *temp = fila->inicio;
        fila->inicio = fila->inicio->prox;
        free(temp);
    }
    fila->fim = NULL;
    free(fila);
}
