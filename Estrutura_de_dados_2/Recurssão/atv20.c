//Fatorial exponencial
#include <stdio.h>
#include <stdlib.h>

int pot(int k, int n, int acc) {
    if(n == 0) {
        return acc;
    }
    return pot(k, n-1, acc*k);
}

int aux(int k, int acc) {
    if(k <= 0) {
        return acc;
    }
    int temp = pot((k-(k-2)), acc , 1);
    return aux(k--, temp);
    
}

int main() {
    int x = aux(4, 1);

    printf("%d \n", x);

    return 0;
}