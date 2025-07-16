#include <stdio.h>
#include <locale.h>

int main(){
  setlocale(LC_ALL, "portuguese");
int A[2][3],B[2][3];

  for(int i = 0; i < 2; i++){
    for(int j = 0; j < 3; j++){
        printf("Insira o %dº elementos da linha %d da matriz A\n", j+1, i+1);
        scanf("%d", &A[i][j]);
         printf("Insira o %dº elementos da linha %d da matriz B\n", j+1, i+1);
        scanf("%d",  &B[i][j]);
    }
  }

  for(int i = 0; i < 2; i++){
    for(int j = 0; j < 3; j++){
        printf("Soma %d e %d das matrizes: %d\n", i+1, j+1, A[i][j]+B[i][j]);
    }
  }



    return 0;
}