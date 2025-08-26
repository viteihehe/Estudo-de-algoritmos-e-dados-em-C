#include <stdio.h>
#include <locale.h>

void iguala(int a);

int main(){
  setlocale(LC_ALL, "portuguese");
  int a;
  
   printf("Insira um valor inteiro:\n");
   scanf("%d", &a);
   iguala(a);

    return 0;
}

void iguala(int a){
    if(a == 0){
        printf("%d é igual a 0\n", a);
    }else{
        printf("%d não é igual a 0\n", a);
    }
}