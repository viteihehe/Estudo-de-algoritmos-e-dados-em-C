#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int maior(int esq, int dir) {
  if (esq < dir)
    return 1;
  return 0;
}

void organizar(int v[], int i, int f) {
  if(i < f) {
    int esq = 2*i+1;
    int dir = 2*i+2;
    int cam = i;
    int *temp = NULL;
    int m = 0;

    if(esq < f && dir < f) {
        m = maior(v[esq], v[dir]);
    }else if(esq < f) {
        m = 0;
    }
    if(m) {
        if(dir < f && v[dir] > v[i]) {
            temp = &v[dir];
            cam = dir;
        }
    }
    else {
        if(esq < f && v[esq] > v[i]) {
            temp = &v[esq];
            cam = esq;
        }
    }
    if(temp != NULL) {
        int pivo = *(temp);
        *(temp) = v[i];
        v[i] = pivo;
        organizar(v, cam, f);
    }
    
  }
}

int main(int argc, char *argv[]) {
  srand(time(NULL));
  int tam = (atoi(argv[1]));
  int v[tam];
  for (int i = 0; i < tam / 2; i++) {
    v[i] = (rand() % 20) + 1;
  }

  for (int i = 0; i < tam / 2; i++) {
    printf("%d ", v[i]);
  }
  printf("\n");
  for(int i = (tam/4)-1; i >= 0; i--) {
    organizar(v, i, tam/2);
  }
  for (int i = 0; i < tam / 2; i++) {
    printf("%d ", v[i]);
  }
  printf("\n");

  return 0;
}