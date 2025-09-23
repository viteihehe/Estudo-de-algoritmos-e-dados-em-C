#include <stdio.h>
#include <locale.h>

int main(){
  setlocale(LC_ALL, "portuguese");
int matriz[3][3];

    for(int i = 0; i < 3; i++){
      for(int j = 0; j < 3; j++){
        printf("Insira o %dº valor na linha %d\n", j+1, i+1);
          scanf("%d", &matriz[i][j]);
      }
    }

    for(int i = 2; i >= 0; i--){
      for(int j = 2; j >= 0; j--){
        printf("%d  ", matriz[i][j]);
      }
    }

    return 0;
}