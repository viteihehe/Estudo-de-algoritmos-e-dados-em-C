//somatorio de 1 até n
#include <stdio.h>


int soma_aux(int n, int acc) {
    if(n == 0) {
        return acc;
    }

    return soma_aux(n-1, acc+n);
}

int soma(int n) {
    return soma_aux(n, 0);
}

int main() {

    int x = soma(3);

    printf("%d\n", x); 
    

}