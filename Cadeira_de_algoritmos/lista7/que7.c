#include <stdio.h>


int main(){

  int i, j, a;
  for( i = 1; i < 12; i++){
     a = 1;
    if(i%2 != 0){
        
        j = i;
      while(j >= 1){
        a =a*j;
        j--;
      }
     printf("%d! = %d\n", i, a);
   }
 }
    return 0;
}