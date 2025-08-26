#include <stdio.h>
#include <locale.h>

int main(){
  setlocale(LC_ALL, "portuguese");
  float a[5], b[5];

  for(int i = 0; i < 5; i++){
    printf("Insira o %dº valor:\n", i+1);
    scanf("%f", &a[i]);

    if(i == 0){
        b[i] = a[i];
    }else if(i%2 == 0){
        b[i] = a[i]*5;
    }else{
        b[i] = a[i]+5;
    }
  }

  for(int i = 0; i < 5; i++){
    printf("A%d: %.2f \n B%d: %.2f\n", i+1, a[i], i+1, b[i]);
  }

    return 0;
}