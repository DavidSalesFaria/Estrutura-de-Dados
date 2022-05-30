#include <stdio.h>
#include <stdlib.h>



int main(){
    int a, b;

    a = 10;
    b = 30;

    int *p = &a, *q = &b;

    printf("\n*p: %d, *q:%d\n", *p, *q);

    // Alterando o valor das variáveis
    // através dos ponteiros
    *p = 2;
    *q = 100;
    printf("\na: %d, b:%d\n", a, b);
    
}