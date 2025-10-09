#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int id;
    int pontos;
} Jogador;

int main() {
    FILE *file = fopen("./player_log.txt", "r+");
    if(file == NULL) {
       printf("Erro ao abrir o arquivo!\n");
        exit(1);
    }
    int n;
    int soma = 0;
    int tempid = -1;
    Jogador j;
    
    fscanf(file, "%d", &n);
    for(int i = 0; i < n; i++) {
      fscanf(file, "%d %d", &j.id, &j.pontos);

       if (tempid == -1)
            tempid = j.id; 

        if (j.id == tempid)
            soma += j.pontos;
    }
        fprintf(file, "\n--- SESSION CONCLUDED ---");
        fseek(file, 0, SEEK_CUR);

        printf("Total de experiencia ganha: %d\n", soma);

    fclose(file);

    return 0;
}