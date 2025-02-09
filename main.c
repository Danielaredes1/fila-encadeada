/* Daniela Souza Costa 
Matrícula: 20242005840
Beatriz Piedade Rodrigues
Matrícula: 20242005699 */

/* Daniela Souza Costa 
Matrícula: 20242005840
Beatriz Piedade Rodrigues
Matrícula: 20242005699 */

#include "fila.h"

int main(){
    while(1){
        fila *minhaFila = criaFila();
        int n;
        lerDeArquivo(minhaFila);
        
        printf("Operações:\n(1) para empilhar;\n(2) para desempilhar;\n(3) para salvar\n(4) para fechar.\n");
        scanf("%d", &n);

        switch (n) {
            case 1:
                dados novoDado;
                printf("digite o nome:\n"); getchar();
                fgets(novoDado.nome, 100, stdin);
                break;
        
            default:
                printf("Operação inválida");
                break;
        }
    }

    return 0;
}


