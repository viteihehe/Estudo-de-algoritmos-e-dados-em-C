#include <stdio.h>
#include <stdlib.h>

int main () {
    int N = 1;

    while(N != 0) {
        printf("Insira o tramanho da matriz:\n");
        scanf("%d",&N);
        int *po = (int*)malloc(N*N*sizeof(int)); 

        int max = N/2;
        if(N % 2 == 0) {
            max++;
        }

         for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                *(po+(i*N)+j) = 0;
            }
        }

        for(int i = 0; i < max; i++) {
            for(int j = 0; j < N; j++) {
                *(po+(i*N)+j) = 1;
               if((i > 0 && i != N-1) && (j != 0 && j != N-1)) {
                    *(po+(i*N)+j) += i+1;
               } 
               if(((N % 2 != 0) && j == N/2 && i == N/2) && N != 3 && N != 1) {
                    *(po+(i*N)+j) += i+1;
                 }
            }
        }

                for(int i = 0; i < N; i++) {
                    for(int j = 0; j < N; j++) {
                        printf(" %3d ", *(po+(i*N)+j));
                    }
                    printf("\n");
                }
            free(po);
        }

                
        


        
    return 0;

}