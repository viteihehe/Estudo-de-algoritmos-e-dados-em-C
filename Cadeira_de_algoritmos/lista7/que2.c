#include <stdio.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL, "portuguese");
 int v = 0;
   for(int i = 1; i <= 500; i++){
     if(i%2 == 0){
        v += i;
     }
   }
   printf("Valor da soma: %d", v);
    return 0;
}