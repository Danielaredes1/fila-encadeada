/* Daniela Souza Costa 
Matrícula: 20242005840
Beatriz Piedade Rodrigues
Matrícula: 20242005699 */

#include "fila.h"

int main(){
    fila *minhaFila = criaFila();
    dados *novoDado;

    while(1){
        int n;
        lerArquivo(minhaFila);
        
        printf("Operações:\n(1) para empilhar;\n(2) para desempilhar;\n(3) para salvar\n(4) para fechar.\n");
        scanf("%d", &n);
        if(n == 4){
            esvaziar(minhaFila);
            desalocar(minhaFila);
            break;
        }

        switch (n) {
            case 1:
                novoDado = (dados *)malloc(sizeof(dados));

                printf("digite o nome:\n"); getchar();
                fgets(novoDado->nome, 100, stdin);

                printf("digite a ideade:\n"); getchar();
                fgets(novoDado->idade, 10, stdin);

                printf("Informe a descrição:\n"); getchar();
                fgets(novoDado->descricao, 100, stdin);

                printf("Dado opcional:\n"); getchar();
                fgets(novoDado->extra1, 50, stdin);

                printf("Dado opcional:\n"); getchar();
                fgets(novoDado->extra2, 50, stdin);

                enfileirar(minhaFila, *novoDado);
                break;

            case 2:
                desenfileirar(minhaFila);
                break;
            case 3:
                salvarArquivo(minhaFila);
        
            default:
                printf("Operação inválida");
                break;
        }
    }

    return 0;
}


