#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct LISTA{
  int dado;
}no;


void teste(int x, no *ptr){
  ptr->dado = x;
  printf("\n%d\n", ptr->dado);
}

void teste2(no *ptr){
  no *novo;
  novo = malloc(sizeof(no));
  novo->dado = 16;

  *ptr = *novo;
}

int main() {

  no *p;
  p = malloc(sizeof(no));
  p->dado = 0;

  printf("\n%d\n", p->dado);
  teste2(p);
  printf("\n%d\n", p->dado);

}