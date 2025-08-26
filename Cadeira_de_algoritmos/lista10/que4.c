#include <stdio.h>
#include <locale.h>

int main(){
  setlocale(LC_ALL, "portuguese");
 float A[4][2], B[4][2];
 float c = 0;

 for(int i = 0; i < 4; i++){
    for(int j = 0;  j < 2; j++){
        printf("Insira o %dº na linha %d\n", j+1, i+1);
        scanf("%f", &A[i][j]);    
    }
 }

 for(int i = 0; i < 4; i++){
    for(int j = 0; j < 2; j++){
        B[i][j] = A[3-i][1-j];
    }
 }

 for(int i = 0; i < 4; i++){
    for(int j = 0;  j < 2; j++){
        printf("A:  %.2f B: %.2f \t\n", A[i][j], B[i][j]);
        
    }
 }

}











 