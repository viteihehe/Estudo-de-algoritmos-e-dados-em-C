#include <stdio.h>

void bubbleSort(int v[], int n) {
    for(int i = 0; i < n-1; i++) {
        int troca = 0;
        for(int j = 0; j < n-1-i; j++) {
            if(v[j] > v[j+1]) {
                int temp = v[j];
                v[j] = v[j+1];
                v[j+1] = temp;
                troca = 1;
            }
         
        }
        if(!troca) {
            return;
        }
        
    }
}

int main() {
    int n;
    printf("Insira a quantidade de jogadoes:\n");
    scanf("%d", &n);

    int v[n];
    for(int i = 0; i < n; i++) {
        printf("Insira o %d valor:\n", i+1);
        scanf("%d", &v[i]);
    }
    bubbleSort(v, n);

    for(int i = n-1; i >= 0; i--) {
        printf("%d ", v[i]);
    }
    printf("\n");
}