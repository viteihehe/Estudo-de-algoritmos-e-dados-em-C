#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct {
    char nome [50];
    int HP;
    int ATK;
} Unidade;

int main() {
    setlocale(LC_ALL, "portuguese");
    int n;
    FILE *file = fopen("squad.dat", "wb");

    printf("Quantas unidades contera o esquadrão?\n");
    scanf("%d", &n);

     Unidade *u = (Unidade *)calloc(n, sizeof(Unidade));

        for(int i = 0; i < n; i++) {
            printf("Insira o nome do %d membro:\n", i+1);
            scanf(" %s", (u+i)->nome);
            printf("Insira o HP e o ATK:\n");
            scanf("%d %d", &(u+i)->HP, &(u+i)->ATK);
        }

        fwrite(u, sizeof(Unidade), n, file);
        fclose(file);

    int indiceMaiorATK = 0;
    
    
    for(int i = 1; i < n; i++) {
        if(u[i].ATK > u[indiceMaiorATK].ATK) {
            indiceMaiorATK = i;
        }
    }

    printf("%s\nATK: %d\n", u[indiceMaiorATK].nome, u[indiceMaiorATK].ATK);
     
     free(u);


    return 0;
}