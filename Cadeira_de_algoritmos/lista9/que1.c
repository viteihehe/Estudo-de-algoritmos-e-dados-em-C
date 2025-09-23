#include <stdio.h>

int main(){
 int v[8];

 for(int i = 0; i < 8; i++){
    printf("Insira o %d valor:\n", i+1);
    scanf("%d", &v[i]);
 }
 for(int i = 7; i >= 0; i--){
    printf("%d ", v[i]);
 }

    return 0;
}