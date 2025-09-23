#include <stdio.h>
#include <locale.h>

int main(){
  setlocale(LC_ALL, "portuguese");
 float nota[5][3];
 float media[5];

 for(int i = 0; i < 5; i++){
    int temp = 0;
   for(int j = 0; j < 3; j++){
    printf("Insira a %dº nota do aluno %d\n", j+1, i+1);
    scanf("%f", &nota[i][j]);

    
    temp += nota[i][j];
    
   }
   media[i] = temp;
 }
 
 for(int i = 0; i < 5; i++){
 
    printf("Aluno %d média: %.2f\n", i+1, media[i]/3);
 }
    return 0;
}