#include <stdio.h>
#include <stdlib.h>


typedef struct lista{
    /*
        Estrutura lista-no

        int conteudo [Conteúdo do nó]
        struct lista *prox [ponteiro de nó que aponta
        para o próximo nó da lista]
    */

    int conteudo;
    struct lista *prox

}no;

void imprimirRecur(no *no){
    /*
    Imprime os elementos da lista encadeada fazendo
    chamadas recursivas.
    
    no *no [Ponteiro de nó que aponta para um nó]
    */

    
    // Se o próximo nó for NULO, então o nó atual
    // é o último.
    if (no->prox == NULL){
        // Printa o conteúdo do último nó
        printf("%d\n", no->conteudo);
    }
    // Senão, aínda não chegou n último nó
    else{
        // Printa o conteúdo do nó
        printf("%d, ", no->conteudo);
        // <<CHAMADA RECURSICA>> para o próximo nó
        imprimirRecur(no->prox);
    }
}


int main(){
    
return 0;
}