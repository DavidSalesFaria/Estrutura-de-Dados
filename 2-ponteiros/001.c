#include <stdio.h>
#include <stdlib.h>

int xi;
int *ptr_xi;

void imprimir(char texto1[30], char texto2[30]){
    printf("\n%s -------------", texto1);
    printf("\n%s\n\n", texto2);


    printf("Valor de xi = %d\n", xi);
    printf("Valor de &xi = %d\n", &xi);
    printf("Valor de ptr_xi = %d\n", ptr_xi);
    printf("Valor de *ptr_xi = %d\n", *ptr_xi);
}


int main(){

    system("cls");

    xi = 10;
    ptr_xi = &xi;
    imprimir("Primeira Atribuicao", "xi = 10\n ptr_xi = &xi;");

    xi = 20;
    imprimir("Alterar o valor da variavel xi diretamente", "xi = 20;");

    *ptr_xi = 30;
    imprimir("Alterar o valor da variavel xi usando o  ponteiro", "*ptr_xi = 30;");

    return 0;
}