#include <stdio.h>

void particao(int v[], int n) {
    int s[n];
    int pivo = v[n-1];
    int e = 0;
    int d = n-1;
    int i;
    for(i = 0; i < n; i++) {
        if(v[i] <= pivo) {
            s[e] = v[i];
            e++;
        }else {
            s[d] = v[i];
            d--;
        }
    }

    for(i = 0; i < n; i++) {
        v[i] = s[i];
    }

}

int particao_unica(int v[], int n) {
    int i;
    int j = -1;
    int pivo = v[n-1];
    int temp;
    for(i = 0; i < n; i++) {
        if(v[i] <= pivo) {
            j++;
            temp = v[j];
            v[j] = v[i];
            v[i] = temp;
        }
    }
    temp = v[j+1];
    v[j+1] = v[n-1];
    v[n-1] = temp;
    return j+1;
}


int main() {
    int v[] = {3, 8, 2, 1, 5};

    particao_unica(v, 5);

    for(int i = 0; i < 5; i++) {
        printf("%d", v[i]);
    }

    return 0;
}
