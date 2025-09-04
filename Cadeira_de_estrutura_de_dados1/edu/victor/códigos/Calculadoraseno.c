#include <stdio.h>
#include <math.h>

int main() {
    int conti = 1;
    
    while(conti) {
        double temp;
        scanf("%lf", &temp);
        double valor_seno = sin(temp*M_PI/8);
        printf("valor_seno: %.2lf\n", valor_seno);

        printf("COnti?\n");
        scanf("%d", &conti);

    }


    return 0;
}