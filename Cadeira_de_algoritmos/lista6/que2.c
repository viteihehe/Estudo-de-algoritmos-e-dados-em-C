#include <stdio.h>

int main(){
    int n, d;

        printf("Insira o numerador:\n");
        scanf("%d", &n);
        printf("Insira o denominador:\n");
        scanf("%d", &d);

        if(d == 0){
            printf("divisão indefinida\n");
        }else if(n%d == 0){
            printf("É divisivel\n");
        }else{
            printf("Não é divisivel\n");
        }
        
    return 0;
}