#include <stdio.h>
#include <string.h>

typedef struct
{
   char nome[50];

} Estudante;


int main() {
    Estudante estudantes[3];

    for(int i = 0; i < 3; i++) {
        printf("Insira o nome do %d estudante:\n", i+1);
        scanf("%s", estudantes[i].nome);
    }

    char temp[50];

    for(int i = 0; i < 2; i++) {
        
        if(strcmp(estudantes[i].nome, estudantes[i+1].nome) > 0) {
            strcpy(temp , estudantes[i].nome);
            strcpy(estudantes[i].nome , estudantes[i+1].nome);
            strcpy(estudantes[i+1].nome, temp);
        }
    }

    for(int i = 0; i < 3; i++) {
      printf("%s\n", estudantes[i].nome);
    }

    return 0;
}