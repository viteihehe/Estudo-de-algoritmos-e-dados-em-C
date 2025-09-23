#include <stdio.h>

int main() {
    int matriz[3][2];
    int matrizb[2][2];
    int re[3][2];

    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 2; j++) {
            printf("Insira na coluna %d linha %d:\n", j+1, i+1);
            scanf("%d", matriz[i][j]);
        }
    }

    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 2; j++) {
            printf("Insira na coluna %d linha %d:\n", j+1, i+1);
            scanf("%d", matrizb[i][j]);
        }
    }

    for(int i = 0; i < 3; i++) {
        int temp = 0;
        for(int j = 0; j < 2; j++) {
            re[0][j] = temp += (matriz[i][j] * matrizb[i][0]);
            re[1][j] = temp += (matriz[i][j] * matrizb[i][0]);
            re[2][j] = temp += (matriz[i][j] * matrizb[i][0]);
        }
    }


}