#include <stdio.h>
#include <string.h>

typedef struct{
    int id;
    char nome [50];
    int diasRestantes;
} Livro;

int busca_binaria (int inicio, int fim, Livro v[], int valor_buscado) {
    if(inicio < fim) {
        int meio = (inicio+fim)/2;
        if(v[meio].id == valor_buscado) {
            return meio;
        }
        if(v[meio].id <= valor_buscado) {
            busca_binaria(meio+1, fim, v, valor_buscado);
        }else {
            busca_binaria(inicio, meio-1, v, valor_buscado);
        }
    }
}

void insertion_sort_id(Livro livros[], int quantidade) {
    int i, j, temp;
    Livro busca;
    for(i = 1; i < quantidade; i++) {
        j = i -1;
        busca = livros[i];
        temp = busca_binaria(0, j, livros, busca.id);
        
    }
   
}


int main() {
    int n;
    scanf("%d", &n);
    Livro livros[n];
    for(int i = 0; i < n; i++) {
        printf("Insira o nome:\n");
            scanf(" %[^\n]s", livros[i].nome);
        printf("Insira o id:\n");
            scanf("%d", &livros[i].id);
        printf("Insira o dia restantes:\n");
            scanf("%d", &livros[i].diasRestantes);
    }

    printf("Ordenado por nome:\n");
    insertion_sort_nome(livros, n);
    for(int i = 0; i < n; i++) {
        printf("Nome: %s\nID: %d\nDias restantes: %d\n", livros[i].nome, livros[i].id, livros[i].diasRestantes);
    }

    printf("Ordenado por id:\n");
    insertion_sort_id(livros, n);
    for(int i = 0; i < n; i++) {
        printf("Nome: %s\nID: %d\nDias restantes: %d\n", livros[i].nome, livros[i].id, livros[i].diasRestantes);
    }


}