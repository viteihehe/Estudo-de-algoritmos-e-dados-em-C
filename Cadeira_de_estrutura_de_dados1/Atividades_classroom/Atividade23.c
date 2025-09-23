#include <stdio.h>
#include <stdlib.h>

#define ERRO do{ \
    printf("\a\aERRO\n"); \
    exit(0); \
}while(0);

#define LINHAS 5
#define COLUNAS 10

int main() {
    int *level_map = (int *) malloc(LINHAS * COLUNAS * sizeof(int));

    if(level_map == NULL) ERRO;

        for(int i = 0; i < LINHAS; i++) {
            for(int j = 0; j < COLUNAS; j++) {
                if(i == LINHAS-1) {
                    *(level_map+(i * COLUNAS) + j) = 1;
                }else {
                    *(level_map+(i * COLUNAS) + j) = 0;
                }
            }
        }

        for(int i = 0; i < LINHAS; i++) {
            for(int j = 0; j < COLUNAS; j++) {
                printf("%d", *(level_map+(i * COLUNAS) + j));
            }
            printf("\n");
        }

        free(level_map);
        level_map = NULL;

    return 0;
}