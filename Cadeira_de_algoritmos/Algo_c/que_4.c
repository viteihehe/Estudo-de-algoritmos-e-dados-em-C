#include <stdio.h>

int main(){
    float c, f;

    printf("Insira o valor em Celsius:\n");
    scanf("%f", &c);

    f = (c*1.8)+32;

    printf("C : %.2f e em F: %.2f\n", c, f);

    return 0;
}