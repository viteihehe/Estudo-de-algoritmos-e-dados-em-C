#include <stdio.h>
#include <stdlib.h>

#define ERRO do{ \
    printf("\a\aERRO\n"); \
    exit(0); \
}while(0);

int main() {
    float *ponteiro_altura_salto_duplo = NULL;

        printf("Jogador ainda nao possui o Salto Duplo.\n");

        ponteiro_altura_salto_duplo = (float *) malloc(sizeof(float));
        if(ponteiro_altura_salto_duplo != NULL) {
            *ponteiro_altura_salto_duplo = 15.5;

            printf("Pena Dourada coletada! Altura do Salto Duplo: %.1f\n", *ponteiro_altura_salto_duplo);
            free(ponteiro_altura_salto_duplo);
           }else{
                ERRO;
           }

        




    return 0;
}