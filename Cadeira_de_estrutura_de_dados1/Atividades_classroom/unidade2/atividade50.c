#include <stdio.h>

int main() {
    float n1,n2,n3;
    printf("insira os 3 numeros:\n");
    scanf("%f %f %f", &n1, &n2, &n3);
    float media = (n1+n2+n3)/3;
    printf("media: %.2f\n", media);
    return 0;
}