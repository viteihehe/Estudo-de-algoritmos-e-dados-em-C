#include <stdio.h>
#include <stdlib.h>

#define ERRO do{ \
    printf("\a\aERRO\n"); \
    exit(0); \
}while(0);

int main() {
    int linha, coluna;

    printf("Insira o número de linhas e de colunas:\n");
        scanf("%d %d", &linha, &coluna);

        int **mapa = (int **) malloc(linha * sizeof(int *));
        for(int i = 0; i < linha; i++){
            mapa[i] = (int *) malloc(coluna * sizeof(int));
        }

        printf("Digite valores 0, 1 ou 2:\n");
            for(int i = 0; i < linha; i++) {
                for(int j = 0; j < coluna; j++) {
                    scanf("%d", &mapa[i][j]);
                }
            }
            
            int tijolos = 0;
            for(int i = 0; i < linha; i++) {
                for(int j = 0; j < coluna; j++) {
                    if(mapa[i][j] == 1) {
                        tijolos++;
                    }
                }
            }

            printf("O mapa possui %d blocos de tijolo.", tijolos);

            for(int i = 0; i < linha; i++) {
                free(mapa[i]);
            }
            free(mapa);

    


    return 0;
}
