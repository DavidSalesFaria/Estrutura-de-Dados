#include <stdio.h>
#include <stdlib.h>

// Vamos testar alocação dinâmica de memória

// Definimos um ponteiro, porém não o faremos
// apondar para uma variável
int *ptr;

int main(){
    system("cls");
    
    // Vamos observar o endereço para o qual
    // o ponteiro aponta, vamos receber um endereço inválido.
    // Se tentarmos observar o valor de *ptr, o programa
    // encerrará com um erro.

    printf("\n1 -------------------");
    printf("\nEndereco: %p\n", ptr);
    
    // Afunção malloc(tam_bytes) reserva um espaço na memória
    // como ptr é um ponteiro de inteiros, vamos querer um
    // espaço de 4 bytes, sizeof(int) retornará isso.
    // Podemos observar que ptr, agora aponta para um
    // endereço válido. Além disso *ptr agora tem um valor.
    // De onde surgiu esse valor? O compilador buscou na memória
    // um bloco de 4bytes disponível e passou o endereço para ptr, 
    // porém, esses bytes já possuiam um valores.
    printf("\n2 -------------------");
    ptr =  (int *) malloc(sizeof(int));
    printf("\nEndereco: %p\n", ptr);
    printf("Valor: %d\n", *ptr);

    // Agora que ptr tem 4 bytes de espaço, podemos atribuir um
    // valor inteiro qualquer a ele. Observe que o seu endereço não mudou.
    printf("\n3 -------------------");
    *ptr = 10;
    printf("\nEndereco: %p\n", ptr);
    printf("Valor: %d\n", *ptr);

    // Agora vamos inicializar uma variável x=10 e atribuir o seu
    // endereço a ptr. Observe que o valor 10 que foi alocado dinamicamente
    // para o ponteiro se perdeu, pois não estava associando a nenhuma variável.
    int x=10;
    ptr = &x;
    printf("Endereco: %p\nValor: %d", ptr, *ptr);

    // É dever do programador liberar a memória que alocou
    // senão a mesma ficará reservada até outro programa libera-la
    // ou até a próxima reinicialização da máquina.
    free(ptr);

    return 0;
}