#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main(){
    // Constante
    #define tam 10

    // Variáveis
    int vetor[tam], i;

    printf("%d", vetor[0]);
    // Vamos testar o nosso novo vetor com um laço
    // que vai preencher o vetor com as potências de 2
    // de 0 à 1.
    
    for(i=0; i<tam; i++){
        vetor[i] = pow(2, i); // 2ⁱ     
    }

    printf("[");
    for(i=0; i<tam; i++){
        printf("%d, ", vetor[i]);
    }
    printf("]");

    return 0;
}