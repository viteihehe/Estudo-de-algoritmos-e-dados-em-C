#include <stdio.h>

void intercalar(int n1, int n2 ,int a[], int b[], int v[]) {
    int i = 0, j = 0, k = 0;
    while(i < n1 && j < n2) {
        if(a[i] < b[j]) {
            v[k] = a[i];
            i++;
        }else {
            v[k] = b[j];
            j++;
        }
      k++;
    }

    while(i < n1) {
        v[k] = a[i];
        i++;
        k++;
    }

    while(j < n2) {
        v[k] = b[j];
        j++;
        k++;
    }
}

int main() {
    int a[] = {1,3,5,8};
    int b[] = {2,4,6,9,10};
    int v[9];

    intercalar(4,5,a,b,v);

    for(int i = 0; i < 9; i++) {
        printf("%d ", v[i]);
    }

    


    return 0;
}