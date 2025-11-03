#include <stdio.h>

void intercalador(int n, int m, int v[], int x[], int r[]) {
    int i = 0, j = 0, k = 0;
    while(i < n && j < m) {
        if(v[i] < x[j]) {
            r[k] = v[i];
            i++;
        }else {
            r[k] = x[j];
            j++;
        }
        k++;
    }
    while(i < n) {
        r[k] = v[i];
        k++;
        i++;
    }
    while(j < m) {
        r[k] = x[j];
        j++;
        k++;
    }
}

int main() {
    int n, m;
    printf("Insira o numero de inimigos do Portal Alfa:\n");
    scanf("%d", &n);
    int v[n];
    for(int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
    }
    printf("Insira o numero de inimigos do Portal Beta:\n");
    scanf("%d", &m);
    int x[m];
    for(int i = 0; i < m; i++) {
        scanf("%d", &x[i]);
    }
    int r[n+m];
    intercalador(n, m, v, x, r);

    for(int i = 0; i < n+m; i++) {
        printf("%d ", r[i]);
    }

    return 0;
}