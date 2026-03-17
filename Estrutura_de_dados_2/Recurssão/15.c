//Fatorial duplo
#include <stdio.h>

int fat_calculo(int n, int acc) {
    if(n == 0) {
        return acc;
    }
    int temp = (n%2 != 0) ? acc*n : acc;
    return fat_calculo(n-1, temp);
}

int fat_duplo(int n) {
    return fat_calculo(n, 1);
}

int main() {

    int x = fat_duplo(5);
    printf("%d ", x);

    return 0;
}