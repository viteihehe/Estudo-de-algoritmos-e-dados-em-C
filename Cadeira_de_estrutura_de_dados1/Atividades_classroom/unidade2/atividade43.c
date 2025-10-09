#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char nome [50];
    int vida;
    int ataque;
} Inimigos ;

int main() {
    FILE *file = fopen("./wave_data.txt", "r");
    if(file == NULL) {
        printf("ERRO!\n");
        system("pause");
        exit(1);
    }
    Inimigos e;
      char maiornome [50];
        int maiorataque;
        int maiorvida;
        int i = 0;

    while(fscanf(file, "%s %d %d", e.nome, &e.vida, &e.ataque) != EOF) {
         if(i == 0) {
         strcpy(maiornome, e.nome);
         maiorataque = e.ataque;
         maiorvida = e.vida;
         i++;
         }
        if(e.ataque > maiorataque) {
            strcpy(maiornome, e.nome);
            maiorataque = e.ataque;
            maiorvida = e.vida;
        }
    }
    printf("Maior Ameaça: %s\nVida: %d\nAtaque: %d\n", maiornome, maiorvida, maiorataque);

    fclose(file);



    return 0;
}