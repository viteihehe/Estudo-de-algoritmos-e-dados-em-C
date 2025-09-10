#include <stdio.h>
#include <stdlib.h>

#define ERRO do{ \
    printf("\a\aERRO\n"); \
    exit(0); \
}while(0);

int main() {
    int *duracao_fumaca = (int *) malloc(sizeof(int));

    if(duracao_fumaca == NULL) ERRO;

        *duracao_fumaca = 5;

        printf("Bomba de fumaca ativada! Duracao: %d segundos.\n", *duracao_fumaca);
        free(duracao_fumaca);
        duracao_fumaca = NULL;

        printf("A fumaca se dissipou\n");




    return 0;
}