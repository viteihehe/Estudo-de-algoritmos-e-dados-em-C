#include <stdio.h>

int main(){
    int m;
    float p;

        printf("Quantas unidades de fruta deseja?\n");
        scanf("%d", &m);

        if(m < 12){
            p = (float)m*1.30;
        }else{
            p = (float)m*1.10;
        }

        printf("Valor a ser pago: %.2f\n", p);

    return 0;
}