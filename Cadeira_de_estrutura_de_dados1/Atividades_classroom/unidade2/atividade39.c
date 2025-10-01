#include <stdio.h>

typedef struct {
    char nome [50];
    float hp;
    float atk;
} Inimigo;

int main() {
    Inimigo *inimigos = (Inimigo *)malloc(3*sizeof(Inimigo));
    if(inimigos == NULL) {
        exit(0);
    }

    FILE *file = fopen("./inimigos.txt", "r");

    for(int i = 0; i < 3; i++) {
        fscanf(file, "%s %f %f", (inimigos+i)->nome, &(inimigos+i)->hp, &(inimigos+i)->atk);
    }

    for(int i = 0; i < 3; i++) {
        float soma = 0;
        soma += (inimigos+i)->hp + (inimigos+i)->atk;
        if(soma >= 200) {
            printf("Nome: %s\n", inimigos[i].nome);
            printf("Nivel de ameaça: %.2f \n", soma);
        }
        
    }


    free(inimigos);
    fclose(file);



    return 0;
}