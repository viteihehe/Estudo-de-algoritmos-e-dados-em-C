#include <stdio.h>

int main() {
    int sala_1[] = {10,20,5};
    int sala_2[] = {50, 100};
    int sala_3[] = {5,5,5,10};
    int *ponteiro_salas[] = { sala_1, sala_2, sala_3 };
    int tamanho[] = {
        sizeof(sala_1)/sizeof(sala_1[0]),
        sizeof(sala_2)/sizeof(sala_2[0]),
        sizeof(sala_3)/sizeof(sala_3[0])
    };

          for(int i = 0; i < 3; i++){
            printf("Moedas na Sala %d: ", (i+1));
            for(int j = 0; j < tamanho[i]; j++){
                printf("%d ", ponteiro_salas[i][j]);
            }
            printf("\n");
          }









    return 0;
}