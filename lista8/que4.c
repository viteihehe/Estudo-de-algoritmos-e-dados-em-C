#include <stdio.h>
#include <locale.h>

void maior(int a);

int main(){
  setlocale(LC_ALL, "portuguese");
  int a;

    printf("Insira a sua idade:\n");
    scanf("%d", &a);
    maior(a);

    return 0;
}

void maior(int a){
    if(a >= 18){
        printf("Você é maior de idade!\n");
    }else{
        printf("VocÊ é menor de idade!\n");
    }
}