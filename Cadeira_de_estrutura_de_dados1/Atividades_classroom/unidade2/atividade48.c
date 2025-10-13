#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char nome [50];
    int vida;
    int ataque;
} Campeao;

int main() {
    Campeao c[3];
    FILE *file = fopen("squad.dat", "rb");
    fread(c, sizeof(Campeao), 3, file);
    fclose(file);

    int tankIndice = 0;
    for(int i = 1; i < 3; i++) {
        if(c[i].vida > c[tankIndice].vida) {
            tankIndice = i;
        }
    }
    printf("%s :Tanque do esquadrao:\n", c[tankIndice].nome);


    return 0;
}