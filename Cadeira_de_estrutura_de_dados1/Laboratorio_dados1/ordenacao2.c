#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int n;
    srand(time(NULL));
    printf("Insira a quantidade de ids:\n");
    scanf("%d", &n);
    int id[n];
    for(int i = 0; i < n; i++) {
        id[i] = (rand() % 30) +1;
    }
    int i, j;
    for(i = 1; i < n ; i++) {
        int x = id[i];
        for(j = i-1; j >= 0 && x < id[j]; j--) {
            id[j+1] = id[j];
        }
        id[j+1] = x;
    }

    return 0;
}