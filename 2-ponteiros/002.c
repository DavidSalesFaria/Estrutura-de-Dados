#include <stdio.h>
#include <stdlib.h>

int xi, *p_xi;
float xf, *p_xf;

int main(){

    xi = 10;
    xf = 2.3;

    p_xi = &xi;
    p_xf = (float *) &xi;


    printf("\n%f\n", *p_xf);
    return 0;
}