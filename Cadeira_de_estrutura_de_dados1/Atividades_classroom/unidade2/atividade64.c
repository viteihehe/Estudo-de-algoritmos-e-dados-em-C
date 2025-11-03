#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    printf("Insira a quantidade de fragmentos:\n");
    scanf("%d", &n);

    int* v = (int *)malloc(n*sizeof(int));
    int i,j;
    for(i = 0 ; i < n; i++) {
        printf("Insira o %d valor:\n", i+1);
        scanf("%d", &v[i]);
    }

    for(i = 1; i < n; i++) {
        int x = v[i];
        for(j = i-1; j >= 0 && x < v[j]; j--) {
            v[j+1] = v[j];
        }
        v[j+1] = x;
    }

    for(i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }

    free(v);
    
    return 0;
}