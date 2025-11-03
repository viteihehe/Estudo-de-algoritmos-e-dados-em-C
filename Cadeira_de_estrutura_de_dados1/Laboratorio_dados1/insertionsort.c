#include <stdio.h>



void insertion_sort(int v[], int n) {
    int i, j;
    for(i = 1; i < n; i++) {
        int x = v[i];
        for(j = i-1; j >= 0 && x < v[j]; j--) {
            v[j+1] = v[j];
        }
        v[j+1] = x;
    }
}



int main() {
    int n;
    printf("Insira a quantidade de id:\n");
    scanf("%d", &n);
    int v[n];

    for(int i = 0; i < n; i++) {
        printf("Insira o id:\n");
        scanf("%d", &v[i]);
    }

    insertion_sort(v, n);

    for(int i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }


    return 0;
}