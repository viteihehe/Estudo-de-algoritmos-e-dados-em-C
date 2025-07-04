#include <stdio.h>
#include <locale.h>

int main(){
  setlocale(LC_ALL, "portuguese");
    int v[10];

    for(int i = 0; i < 10; i++){
        printf("Insira o %dº valor:\n", i+1);
        scanf("%d", &v[i]);
    }

    for(int i = 0; i < 7; i++){
      for(int j = i+1; j < 8; j++){
        if(v[i] > v[j]){
            int temp = v[i];
            v[i] = v[j];
            v[j] = temp;
        }
      }
    }

    printf("Maior valor: %d\n", v[7]);



    return 0;
}