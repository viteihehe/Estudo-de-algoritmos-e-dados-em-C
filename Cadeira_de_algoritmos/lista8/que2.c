#include <stdio.h>
#include <locale.h>

void tipo(int a);

int main(){
  setlocale(LC_ALL, "portuguese");
  int a;

  printf("Insira um valor inteiro:\n");
  scanf("%d", &a);
  tipo(a);


    return 0;
}

void tipo(int a){
     if(a > 0){
        printf("%d é positivo\n", a);
    }else if(a == 0){
        printf("%d é neutro\n", a);
    }else{
        printf("%d é negativo\n", a);
    }
}