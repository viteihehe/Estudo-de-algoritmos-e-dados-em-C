#include <stdio.h>
#include <stdlib.h>
#include <math.h>


typedef struct {
    int x;
    int y;
} Unidade;

int main() {

    int n;

    printf("Insira a quantidade de unidades:\n");
    scanf("%d", &n);
    
    Unidade *u = (Unidade *)malloc(n*sizeof(Unidade));

    for(int i = 0; i < n; i++) {
            printf("Insira a coodenada X da unidade %d:\n", i+1);
            scanf("%d", &u[i].x);
             printf("Insira a coodenada Y da unidade %d:\n", i+1);
            scanf("%d", &u[i].y);
    }

    float raio;
    printf("Insira o raio de explosao:\n");
    scanf("%f", &raio);
    int contador = 0;

    for(int i = 0; i < n-1; i++) {
        for(int j = i+1; j < n; j++) {
            float distancia = sqrt(pow(u[j].x - u[i].x, 2) + pow(u[j].y - u[i].y, 2));
            if(distancia <= raio) {
                contador++;
            }  
        }
    }

    printf("Contagem de duplas proximas: %d\n", contador);

    free(u);

    return 0;
}