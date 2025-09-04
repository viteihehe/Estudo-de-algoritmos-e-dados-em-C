#include <stdio.h>
#include <stdlib.h>

int main() {
    float *numeros = (float *) malloc(6 * sizeof(float));
    int positivo = 0; 
    float soma = 0;

        for(int i = 0; i < 6; i++) {
            printf("Insira o %d valor:\n", i+1);
            scanf("%f", numeros+i);
        }

        for(int i = 0; i < 6; i++) {
             if(*(numeros+i) >= 0) {
                    positivo++;
                    soma += *(numeros+i);
                }
        }

        printf("%d valores positivos\n%.1f", (int) positivo, soma/positivo);

    return 0;
}