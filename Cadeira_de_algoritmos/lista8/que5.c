#include <stdio.h>
#include <locale.h>

void mult5(int a);

int main(){
  setlocale(LC_ALL, "portuguese");
  int a;

  printf("Insira um valor inteiro:\n");
  scanf("%d", &a);
  mult5(a);
  
    return 0;
}

void mult5(int a){
    if(a%5 == 0){
        printf("%d é multiplo de 5\n", a);
    }else{
        printf("%d não é multiplo de 5\n", a);
    }
}