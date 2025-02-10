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
    no *novo = (no *)malloc(sizeof(no));
    if(novo == NULL){
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
    FILE *arquivo = fopen("conteudo.txt", "a");
    if(arquivo == NULL) exit(1);

    d.nome[strcspn(d.nome, "\n")] = '\0';
    d.idade[strcspn(d.idade, "\n")] = '\0';
    d.descricao[strcspn(d.descricao, "\n")] = '\0';
    d.extra1[strcspn(d.extra1, "\n")] = '\0';
    d.extra2[strcspn(d.extra2, "\n")] = '\0';


    fprintf(arquivo, "%s,%s,%s,%s,%s\n", d.nome, d.idade, d.descricao, d.extra1, d.extra2);
    printf("Dado enfileirado com sucesso!\n");
    fclose(arquivo);
}

void desenfileirar(fila *fila){
    if(testeVazia(fila)) {
        printf("A fila já está vazia");
        return;
    }
    FILE *arquivo = fopen("conteudo.txt", "r");
    if(arquivo == NULL) exit(1);

    FILE *arqtemp = fopen("temp.txt", "w");
    if(arqtemp == NULL) exit(1);


    no *temp = fila->inicio;
    fila->inicio = fila->inicio->prox;

    if(fila->inicio == NULL){
        fila->fim = NULL;
    }

    printf("Dado desenfileirado:\n");
    printf("Nome: %s\nIdade: %s\nDescrição: %s\nExtra 1: %s\nExtra 2: %s\n", temp->dado.nome, temp->dado.idade, 
    temp->dado.descricao, temp->dado.extra1, temp->dado.extra2);

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

void esvaziar(fila *fila){
    if(testeVazia(fila)) {
        printf("A fila já está vazia");
        return;
    }

    FILE *arquivo = fopen("conteudo.txt", "r+");
    if(arquivo == NULL) exit(1);

    while(fila->inicio != NULL){
        desenfileirar(fila);
    }
    fila->fim = NULL;
    arquivo = NULL;
    fclose(arquivo);
}

void imprimir(fila *fila){
    for(no *temp = fila->inicio; temp != NULL; temp = temp->prox){
        printf("nome: %s, idade; %s, compromisso: %s, extra1: %s, extra2: %s\n", 
        temp->dado.nome, temp->dado.idade, temp->dado.descricao, temp->dado.extra1, temp->dado.extra2);
    }
}

void lerArquivo(fila *fila){
    dados *novoDado;
    novoDado = (dados *)malloc(sizeof(dados));

    printf("digite o nome:\n"); getchar();
    fgets(novoDado->nome, 100, stdin);

    printf("digite a ideade:\n"); 
    fgets(novoDado->idade, 10, stdin);

    printf("Informe a descrição:\n"); 
    fgets(novoDado->descricao, 100, stdin);

    printf("Dado opcional:\n"); 
    fgets(novoDado->extra1, 50, stdin);

    printf("Dado opcional:\n");
    fgets(novoDado->extra2, 50, stdin);

    enfileirar(fila, *novoDado);

}

void salvarArquivo(fila *fila){
    FILE *arquivo = fopen("conteudo.txt", "w");
    if(arquivo == NULL) exit(1);

    no *temp = fila->inicio;

    while (temp != NULL) {
        temp->dado.nome[strcspn(temp->dado.nome, "\n")] = '\0';
        temp->dado.idade[strcspn(temp->dado.idade, "\n")] = '\0';
        temp->dado.descricao[strcspn(temp->dado.descricao, "\n")] = '\0';
        temp->dado.extra1[strcspn(temp->dado.extra1, "\n")] = '\0';
        temp->dado.extra2[strcspn(temp->dado.extra2, "\n")] = '\0';
     
        fprintf(arquivo, "%s,%s,%s,%s,%s\n", temp->dado.nome, temp->dado.idade, temp->dado.descricao, temp->dado.extra1, temp->dado.extra2);
        temp = temp->prox;
    }
    fclose(arquivo);
}
