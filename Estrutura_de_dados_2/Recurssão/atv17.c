//Faotrial quadripla
#include <stdio.h>

int fat_aux(int n, int acc, int acc2) {
    if(n == 0) {
        int v [2] = {
            acc, acc2
        };
        return v; 
    }
    return fat_aux(n-1, acc*n, acc2*(2*n));
}

int fat_quadro(int n) {
    return fat_aux(n, 1, 1);
}

int main() {
    

    return 0;
}