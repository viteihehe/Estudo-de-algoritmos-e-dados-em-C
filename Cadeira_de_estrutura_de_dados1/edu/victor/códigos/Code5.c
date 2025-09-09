#include <stdio.h>
#include <stdlib.h>

int main() {
    double *p = (double *) calloc(9, sizeof(double));

    if(p == NULL) {
        printf("ERRO");
        exit(0);
    }

    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            printf("Insira a %d nota do aluno %d\n", j+1, i+1);
            scanf("%lf", p+(i*3)+j);
        }
    }
    int contMaior = 0;
    double maior = p[0];
   
    for(int i = 0; i < 9; i++) {
        if(*(p+i) >= 7) {
            contMaior++;
        }
        if(maior < *(p+i)) {
            maior = *(p+i);
        }
    }

    printf("Quantidade de notas maiores ou iguais a 7.0: %d\n", contMaior);
    printf("Maior nota: %lf\n", maior);

    free(p);

    p = NULL;

    return 0;
}