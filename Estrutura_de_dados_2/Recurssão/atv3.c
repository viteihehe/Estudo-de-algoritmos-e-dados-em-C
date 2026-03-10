//Reversão de numero
#include <stdio.h>




int aux(int n, int temp) {
    if(n <= 9) {
        return temp+n;
    }

    return aux(n/10, (temp + n%10)*10);
}

int inversor(int n) {
    return aux(n, 0);
}


int main() {

    int x = inversor(4321);

    printf("%d\n", x);

    return 0;
}