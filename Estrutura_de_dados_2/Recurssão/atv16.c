//Super fatorial
#include <stdio.h>
#include <stdlib.h>


int fat (int n, int acc) {
    if(n == 0) {
        return acc;
    }
    return fat(n-1, acc*n);
}

int sf_aux(int n, int acc) {
    if(n <= 1) {
        return acc;
    }
    int temp = fat(n, 1);
    return sf_aux(n-1, acc*temp);
}

int sf(int n) {
    return sf_aux(n, 1);
}


int main(int argc, char *argv []) {

    int x = atoi(argv[1]);

    printf("Superfatorial: %d\n", sf(x));
    
    return 0;
}