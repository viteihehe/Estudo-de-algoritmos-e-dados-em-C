#include <stdio.h>
#include <locale.h>

void main(){
    setlocale(LC_ALL, "portuguese");
    int a, i = 0;
    while(i < 11){
        printf("Insira a sua idade:\n");
        scanf("%d", &a);
          if(a >= 18){
            printf("Você é maior de idade!\n");
          }else{
            printf("Você é menor de idade!\n");
          }
        i++;
    }
}