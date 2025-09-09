#include <stdio.h>
#include <string.h>


int main() {
    char nome1[50];
    char nome2[50];
    char nome3[50];
    char *ponteiro[3] = {nome1, nome2, nome3}; 

    for(int i = 0; i < 3; i++) {
        printf("Insira o nome do %d estudante:\n", i+1);
        scanf("%s", ponteiro[i]);
    }

    char temp[50];

    printf("===============\n");

    for(int i = 0; i < 2; i++) {
        
        if(strcmp(ponteiro[i], ponteiro[i+1]) > 0) {
            strcpy(temp, ponteiro[i]);
            strcpy(ponteiro[i], ponteiro[i+1]);
            strcpy(ponteiro[i+1], temp);
        }
    }

    for(int i = 0; i < 3; i++) {
      printf("%s\n", ponteiro[i]);
    }

    return 0;
}