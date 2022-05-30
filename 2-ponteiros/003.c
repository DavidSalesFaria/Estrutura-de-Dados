#include <stdio.h>
#include <stdlib.h>

// Inicializamos as variaveis inteiras a, b e c 
// e um ponteiro inteiro. Lembre que cada valor inteiro
// ocupa 4 bytes na memória, por isso as variáveis inteiras
// são um espaço de 4 bytes.
int a, b, c, *p_int;


int main(){
    system("cls");
    
    // Inserimos valores nas variáveis
    a = 10;
    b = 20;
    c = 30;

    // Agora vamos usar o ponteiro inteiro
    // Vamos começar pela variável do meio
    p_int = &b;
    printf("\nEndereco em p_int ->b = %p\n", p_int);
    printf("Valor em *p_int ->b = %d\n", *p_int);

    // Agora vamos navegar pela memória:
    // &b - 1, nos faz pular 4 bytes para trás
    // assim, apontamos para valriavel inteira imetiatamente anterior a b
    p_int = &b-1;
    printf("\nEndereco em p_int ->b-1 = %p\n", p_int);
    printf("Valor em *p_int ->b-1 = %d\n", *p_int);

    // &b + 1, nos faz pular 4 bytes para frente
    // assim, apontamos para valriavel inteira imetiatamente posterior a b
    p_int = &b+1;
    printf("\nEndereco em p_int ->b+1 = %p\n", p_int);
    printf("Valor em *p_int ->b+1 = %d\n", *p_int);
 
    return 0;
}