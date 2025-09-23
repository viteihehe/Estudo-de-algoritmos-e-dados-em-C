#include <stdio.h>

int main() {
    int n = 1;

    while(n != 0) {
        scanf("%d", &n);
        int max = n/2;
        if(n % 2 != 0) {
            max++;

        }

        int m[n][n];
        for(int i = 0; i < max; i++) {
            for(int j = i; j < n - i; j++) {
                int x = (i+1);
                m[i][j] = x;
                m[j][i] = x;
                m[j][n-1-i] = x;
                m[n-i-1][j] = x;
            }
        }

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                printf(" %3d ", m[i][j]);
            }
            printf("\n");
        }






    }




}