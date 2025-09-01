#include <stdio.h>
#include <stdlib.h>

int main() {
    int temp, cont = 0;

    for(int i = 0; i < 5; i++) {
        printf("Insira um numero:\n");
        scanf("%d", &temp);
        if(temp % 2 == 0) {
            cont++;
        }
    }

    printf("%d valores pares \n", cont);



}