#include <stdio.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL, "portuguese");

    printf("Hello, World!\nHello, \nWorld!\n \tHello, World!\n Hello,\n \tWorld!\n");
   
    return 0;
}