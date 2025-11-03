#include <stdio.h>

typedef struct{
    int id;
    int nivel_ameaca;
} Nave_inimiga;

void intercala(int inicio, int meio, int fim, Nave_inimiga v[]) {
   int n1 = (meio-inicio)+1;
   int n2 = (fim-meio);
   int k = inicio;
   Nave_inimiga v1[n1];
   Nave_inimiga v2[n2];
   int i, j;
   
   for(i = 0; i < n1; i++) {
    v1[i] = v[inicio+i];
   }
   for(j = 0; j < n2; j++) {
    v2[j] = v[meio+1+j];
   }
   i = 0;
   j = 0;
   while(i < n1 && j < n2) {
    if(v1[i].nivel_ameaca < v2[j].nivel_ameaca) {
        v[k] = v1[i];
        i++;
    }else {
        v[k] = v2[j];
        j++;
    }
    k++;
   }

   while(i < n1) {
    v[k] = v1[i];
    i++;
    k++;
   }

   while(j < n2) {
    v[k] = v2[j];
    j++;
    k++;
   }

}

void merge_sort(int i, int f, Nave_inimiga v[]) {
    if(i < f) {
        int m = (i+f)/2;
        merge_sort(i, m, v);
        merge_sort(m+1, f, v);
        intercala(i, m, f, v);
    }
}



int main() {
    int n;
    printf("Insira a quantidades de naves:\n");
    scanf("%d", &n);
    Nave_inimiga naves[n];
    int id = 1;
    for(int i = 0; i < n; i++) {
       printf("Insira o id:\n");
       scanf("%d", &naves[i].id);
       printf("Insira o nivel de ameaça:\n");
       scanf("%d", &naves[i].nivel_ameaca);
    }

    merge_sort(0, n, naves);

    printf("Ordem crescente:\n");
    for(int i = 0; i < n; i++) {
        printf("ID: %d ", naves[i].id);
    }


    return 0;
}