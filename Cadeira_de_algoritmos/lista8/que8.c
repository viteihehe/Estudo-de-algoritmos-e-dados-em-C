#include <stdio.h>
#include <locale.h>

int fat(int a);

int main(){
 setlocale(LC_ALL, "portuguese");
 int a, f;

 printf("Insira um número para ter seu fatorial calculado:\n");
 scanf("%d", &a);

 f = fat(a);

 printf("%d! = %d\n", a ,f);

    return 0;
}

int fat(int a){
    if(a > 1){
        return a*fat(a-1);
    }else{
        return 1;
    }
}