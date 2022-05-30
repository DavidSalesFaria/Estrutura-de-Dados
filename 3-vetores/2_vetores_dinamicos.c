#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main(){


    int tam; // Tamanho do vetor
    int *vetor; // Ponteiro de inteiro que será o vetor
    printf("Escolha o tamanho do vetor: ");
    scanf("%d", &tam);
    // Alocamos vários blocos de 4 bytes para o ponteiro
    // OBS: Sabia que um vetor é um ponteiro?
    vetor = (int *) malloc(sizeof(int) * tam);

    // Vamos testar o nosso novo vetor com um laço
    // que vai preencher o vetor com as potências de 2
    // de 0 à 1.
    int i;
    for(i=0; i<tam; i++){
        vetor[i] = pow(2, i); // 2ⁱ
        printf("Posicao %d: %d\n", i, vetor[i]);
    }
    
    return 0;
}