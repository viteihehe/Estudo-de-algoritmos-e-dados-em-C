#include <stdio.h>
#include <locale.h>

int main(){
  setlocale(LC_All, "portuguese");
    int cont = 0;
  for(int i = 10; i <= 50; i++){
    if(i%2 == 0){
        cont++;
        printf("%d \n", i);
    }
  }
  printf("%d valores!\n", cont);
    return 0;
}