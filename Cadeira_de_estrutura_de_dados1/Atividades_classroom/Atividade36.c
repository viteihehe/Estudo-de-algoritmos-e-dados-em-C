#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
    int posicao_x;
    int posicao_y;
    int valor;
} Moeda;

int main() {
    int quantidade;
    printf("Quantas moedas serão amarzenadas: \n");
    scanf("%d", &quantidade);

        Moeda *pmoeda = (Moeda *) malloc(quantidade*sizeof(Moeda));
        if(pmoeda == NULL) {
            printf("Erro!");
            exit(0);
        }

            for(int i = 0; i < quantidade; i++) {
                printf("Insira a posicao x, a posicao y e o valor da moeda %d\n", i+1);
                scanf("%d %d %d", &pmoeda[i].posicao_x, &pmoeda[i].posicao_y, &pmoeda[i].valor);
            }
                int soma = 0;

                for(int i = 0; i < quantidade; i++) {
                    soma += pmoeda[i].valor;
                }

                printf("Pontuacao maxima do nivel: %d\n", soma);

                free(pmoeda);
                pmoeda = NULL;



    return 0;
}

