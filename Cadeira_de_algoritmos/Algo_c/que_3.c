#include <stdio.h>

int main(){
    int n;

    printf("Insira um valor:\n");
    scanf("%d", &n);

    printf("Sucessor: %d\n", n+1);
    printf("Antecessor: %d\n", n-1);
    return 0;
}