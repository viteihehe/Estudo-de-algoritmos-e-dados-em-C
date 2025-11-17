#include <stdio.h>

// V = [1, 4, 7, 9, 2, 5, 8, 10]
void intercalaUnico(int n, int v[]) {
    int meioa = n/2;
    int meiob = meioa;
    if(n % 2 != 0) {
      meiob++;
    }
    int a[meioa];
    int b[meiob];
    
    int i, j;

    for(i = 0; i < meioa; i++) {
        a[i] = v[i];
    }
    for(j = 0; j < meiob; j++) {
        b[j] = v[meioa+1+j]; 
    }

    i = 0;
    j = 0;
    int k = 0;
    while(i < meioa && j < meiob) {
        if(a[i] < b[j]) {
            v[k] = a[i];
            i++;
            
        }else{
            v[k] = b[j];
            j++; 
        }
        k++;
    }

    while(i < meioa) {
        v[k] = a[i];
        i++;
        k++;
    }
    while(j < meiob) {
        v[k] = b[j];
        j++;
        k++;
    }

}

void intercalar(int inicio, int fim, int v[]) {
    int meio = (inicio+fim)/2;
    int tamanho1 = (meio-inicio)+1;
    int tamanho2 = (fim-meio);
    int a[tamanho1];
    int b[tamanho2];

    int i, j, k = 0;
    for(i = 0; i < tamanho1; i++) {
        a[i] = v[inicio+i];
    }
    for(j = 0; j < tamanho2; j++) {
        b[j] = v[meio+1+j];
    }

    i = 0;
    j = 0;
     while(i < tamanho1 && j < tamanho2) {
        if(a[i] < b[j]) {
            v[k] = a[i];
            i++;
            
        }else{
            v[k] = b[j];
            j++; 
        }
        k++;
    }

    while(i < tamanho1) {
        v[k] = a[i];
        i++;
        k++;
    }
    while(j < tamanho2) {
        v[k] = b[j];
        j++;
        k++;
    }


}

int main() {
    // V = [1, 4, 7, 9, 2, 5, 8, 10]
    int v[] = {1, 4, 7, 9, 2, 5, 8, 6, 10};

    intercalar(0, 8, v);

    for(int i = 0; i < 9; i++) {
        printf("%d ", v[i]);
    }

    return 0;
}