#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int charactere;
    int frequencia;
} Elemento;

typedef struct  {
    Elemento *tab_ax;
} Tabela;


void particao(int i, int f, int m, Elemento *);
void merge_sort(int i, int f, Elemento *);
Tabela contador(char *);

int main() {

    char texto [100];
    printf("Insira o texto para ser comprimido:\n");
    scanf( "%[^\n]s", texto);

    int i = 0;
    Tabela tabela = contador(texto);
    int tam = 0;
    while(tabela.tab_ax[i].charactere != '@') {
        tam++;
        i++;
    }
    merge_sort(0, tam-1, tabela.tab_ax);

    i = 0;
    printf("ASCII/ FREQ\n");
    while(tabela.tab_ax[i].charactere != '@') {
        printf("%c  %d\n", tabela.tab_ax[i].charactere, tabela.tab_ax[i].frequencia);
        i++;
    }

    free(tabela.tab_ax);

    return 0;
}

Tabela contador(char *txt) {
    int tam = strlen(txt);
    int k = 0;
    char letras [tam+1];
    letras[k] = txt[0];
    letras[k+1] = '\0';

    for(int i = 0; i < tam; i++) {
        int achou = 0;
        for(int j = 0; j < strlen(letras); j++) {
            if(letras[j] == txt[i]) {
                achou = 1;
                break;
            }
        }
        if(!achou) {
            k++;
            letras[k] = txt[i];
            letras[k+1] = '\0';
        }
    }

    int total_de_letras = strlen(letras);
    Tabela tabela;
    tabela.tab_ax = (Elemento*)calloc(total_de_letras+1, sizeof(Elemento));

    for(int i = 0; i < total_de_letras; i++) {
        tabela.tab_ax[i].charactere = letras[i];
    }

    tabela.tab_ax[total_de_letras].charactere = '@';

    for(int i = 0; i < total_de_letras; i++) {
        int cont = 0;
        for(int j = 0; j < tam; j++) {
            if(tabela.tab_ax[i].charactere == txt[j]) {
                cont++;
            }
        }
        tabela.tab_ax[i].frequencia = cont;
    }

    return tabela;

}

void particao(int i, int f, int m, Elemento *tabela) {
    int tam1 = (m-i)+1;
    int tam2 = (f-m);
    int temp = i;
    Elemento tab1 [tam1];
    Elemento tab2 [tam2];

    int a, b;
    for(a = 0; a < tam1; a++) {
        tab1[a] = tabela[a+i];
    }
    for(b = 0; b < tam2; b++) {
        tab2[b] = tabela[m+b+1];
    }
    a = 0, b = 0;

    while(a < tam1 && b < tam2) {
        if(tab1[a].frequencia < tab2[b].frequencia) {
            tabela[temp] = tab1[a];
            a++;
        } else {
            tabela[temp] = tab2[b];
            b++;
        }
        temp++;
    }

    while(a < tam1) {
        tabela[temp] = tab1[a];
        temp++;
        a++;
    }

    while(b < tam2) {
        tabela[temp] = tab2[b];
        temp++;
        b++;
    }

}
void merge_sort(int i, int f, Elemento *tab) {
    if(i < f) {
        int m = (i+f)/2;
        merge_sort(i, m, tab);
        merge_sort(m+1, f, tab);
        particao(i, f, m, tab);
    }
}
