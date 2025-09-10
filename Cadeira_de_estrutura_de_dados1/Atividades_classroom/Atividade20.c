#include <stdio.h>
#include <stdlib.h>

#define ERRO do{ \
    printf("\a\aERRO\n"); \
    exit(0); \
}while(0);

int main() {
    void *ponteiro_duracao = malloc(sizeof(int));

    if(ponteiro_duracao == NULL) ERRO;

        *((int *) ponteiro_duracao) = 10;

        printf("Power-up 'Super Salto' ativado! Duracao: %d segundos\n",*((int *) ponteiro_duracao));

        *((int *) ponteiro_duracao) -= 3;
        
            printf("3 segundos se passaram... Duracao restante: %d segundos\n", *((int *) ponteiro_duracao));
            free(ponteiro_duracao);


    return 0;
}