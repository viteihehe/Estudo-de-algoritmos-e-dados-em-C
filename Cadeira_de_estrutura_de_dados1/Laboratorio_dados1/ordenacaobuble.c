#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void ordenabolha(int v[], int n) {
    for(int i = 0; i < n-1; i++) {
        for(int j = i+1; j < n; j++) {
            if(v[j] < v[i]) {
                int temp = v[i];
                v[i] = v[j];
                v[j] = temp;
            }
        }
    }
}

void ordenacaoSelection(int v[], int n) {
    int i, j;
    for(i = 0; i < n-1; i++) {
        int imenor = i;
        for(j = i+1; j < n; j++) {
            if(v[j] < v[imenor]) {
                imenor = j;
            }
        }
        int temp = v[i];
        v[i] = v[imenor];
        v[imenor] = v[i];
    }
}

void ordenacaoPorInsercao(int v[], int n) {
    int i, j;
    for(i = 1; i < n; i++) {
        int menor = v[i];
        for(j = i-1; j >= 0 && menor < v[j]; j--) {
            v[j+1] = v[j];
        }
    }
    v[j+1] = v[i];
}

int main() {
    int n;
    srand(time(NULL));
    printf("Insira a quantidade de ids:\n");
    scanf("%d", &n);
    int id[n];
    for(int i = 0; i < n; i++) {
        id[i] = (rand() % 30) +1;
    }
    
    for(int i = 0; i < n; i++) {
        printf("%d ", id[i]);
    }

    return 0;
}