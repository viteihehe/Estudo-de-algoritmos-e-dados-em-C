#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
   float notas[3];
} Aluno;

int main() {

    Aluno a1, a2, a3;

    float *alunos[3] = {a1.notas, a2.notas, a3.notas};

    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            printf("Insira a %d nota do aluno %d\n", j+1, i+1);
            scanf("%f", *(alunos+i)+j);
        }
    }
    int contMaior = 0;
    float maior = **alunos+0+0;
   
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if(*(*(alunos+i)+j) >= 7) {
                contMaior++;

            }
            if(*(*(alunos+i)+j) > maior)  {
                maior = *(*(alunos+i)+j);
            }
        }
        
    }

    printf("Quantidade de notas maiores ou iguais a 7.0: %d\n", contMaior);
    printf("Maior nota: %.2f\n", maior);

    

    return 0;
}