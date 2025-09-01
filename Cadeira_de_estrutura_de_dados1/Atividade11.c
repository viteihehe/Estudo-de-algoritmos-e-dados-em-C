#include <stdio.h>

int main() {
    int balas[2] = {30, 30};
    int granadas[2] = {5, 5};
    int foguetes[2] = {2,2};
    int *inventario[3] = {balas, granadas, foguetes};

    printf("Inventario inicial:\n");
    printf("Balas: %d\n", *(inventario[0]+0));
    printf("Granadas: %d\n", *(inventario[1]+0));
    printf("Foguetes: %d\n", *(inventario[2]+0));

    for(int i = 0; i < 3; i++){
        *(inventario[i] + 0) -= 1;
    }

    printf("Inventario Apos uso:\n");
    printf("Balas: %d\n", *(inventario[0]+0));
    printf("Granadas: %d\n", *(inventario[1]+0));
    printf("Foguetes: %d\n", *(inventario[2]+0));



    return 0;
}