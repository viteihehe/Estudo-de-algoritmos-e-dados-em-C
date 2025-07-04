#include <stdio.h>
#include <locale.h>

int main(){
  setlocale(LC_ALL, "portuguese");
  int v1[5], v2[5], a; 
  

  for(int i = 0; i < 5; i++){
    a = 1;
    do{
      printf("Insira o %dº valor:\n", i+1);
      scanf("%d", &v1[i]);
     }while(v1[i] < 0);
    for(int j = v1[i]; j >= 1; j--){
        a *= j; 
    }
    v2[i] = a;
  }

  for(int i = 0; i < 5; i++){
    printf("%d-v1: %d %d-v2: %d \n", i+1, v1[i], i+1, v2[i]);
  }

    return 0;
}