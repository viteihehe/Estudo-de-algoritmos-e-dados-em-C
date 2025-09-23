#include <stdio.h>
#include <locale.h>

void paim(int a);

int main(){
  setlocale(LC_ALL, "portuguese");
  int a;

  printf("Insira um número inteiro:\n");
  scanf("%d", &a);
  paim(a);

    return 0;
}

void paim(int a){
    if(a%2 == 0){
        printf("%d é par!\n", a);
    }else{
        printf("%d é impar!\n", a);
    }
}