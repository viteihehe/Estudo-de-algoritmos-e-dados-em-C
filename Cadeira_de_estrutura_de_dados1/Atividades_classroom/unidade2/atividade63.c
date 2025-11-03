#include <stdio.h>

int main() {
    int v[6] = {120, 125, 130, 142, 150};
    int novo_tempo;
    printf("Insira um novo elemento:\n");
    scanf("%d", &novo_tempo);

    int i;
    for( i = 5-1; i >= 0 && novo_tempo < v[i]; i--) {
        if(!(novo_tempo < v[0])) {
           v[i+1] = v[i];
        }
        
    }
    v[i+1] = novo_tempo;

    for(i = 0; i < 5; i++) {
        printf("%d ", v[i]);
    }

    return 0;
}