#include <stdio.h>

void ler_cenario(int n, int *ponteiro_cenario);

int main() {
  int n;
  int *pn = &n;

  printf("Insira o numero de blocos: \n");
    scanf("%d", pn);

    int cenario[n];
  
    ler_cenario(n, cenario);

    for(int i = 0; i < n; i++) {
        if(*(cenario + i)) {
            *(cenario+i) = 2;
            break;
        }
    }
    
    for(int i = 0; i < n; i++) {
        printf("%d ", *(cenario + i));
    }



    return 0;
}

void ler_cenario(int n, int *ponteiro_cenario) {

    for(int i = 0; i < n; i++) {
        printf("Insira 0 ou 1:\n");
        scanf("%d", ponteiro_cenario + i);
    }

}