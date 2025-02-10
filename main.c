/* Daniela Souza Costa 
Matrícula: 20242005840
Beatriz Piedade Rodrigues
Matrícula: 20242005699 */

#include "fila.h"

int main(){
    fila *minhaFila = criaFila();

    while(1){
        int n;
        printf("Operações:\n(1) para empilhar;\n(2) para desempilhar;\n(3) para salvar\n(4) para fechar.\n");
        scanf("%d", &n);
        if(n == 4){
            esvaziar(minhaFila);
            desalocar(minhaFila);
            break;
        }

        switch (n) {
            case 1:
                lerArquivo(minhaFila);
                break;

            case 2:
                desenfileirar(minhaFila);
                break;
            case 3:
                salvarArquivo(minhaFila);
                break;
            default:
                printf("Operação inválida");
                break;
        }
    }

    return 0;
}
