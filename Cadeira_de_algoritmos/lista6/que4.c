#include <stdio.h>

int main(){
    int n;
        printf("Insira um valor inteiro:\n");
        scanf("%d", &n);

        if(n == 0){
            printf("Neutro\n");
        }else if(n<0){
            printf("Negativo");
        }else{
            printf("Positivo");
        }

    return 0;
}