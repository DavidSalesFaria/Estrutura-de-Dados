#include <stdio.h>
#include <stdlib.h>

// AINDA NÃO ESTÁ TERMINADO!!!!!


/*Em uma estrutura de dados fila, 
o último elemento a entrar é o primeiro a sair*/

// Constante
#define tamanho 3
// Estrutura fila
struct fila{
    /*
    (int) dados[tamanho] [Vetor que irá conter os dados
    da fila]
    (int) inicio [Valor inteiro que aponta para o início da fila]
    (int) fim [Valor inteiro que  aponta para a primeira
    posição disponível da fila, ou seja o fim da fila]
    */

    int dados[tamanho];  // dados da fila
    int inicio; // inicio da fila
    int fim; // fim da fila
};

struct fila f1;
// Procedimento para mostrar o conteúdo da fila
void fila_mostrar(struct fila f){
    int i;
    printf("\n["); // abre chaves
    // Laço para imprimir todos os valores da fila
    for (i=0; i<tamanho; i++){
        // Estrutura condicional para formatar
        // a impresssão [val1, val2, ...val3]
        if(i+1 < tamanho)
            printf("%d, ", f.dados[i]);
        else
            printf("%d", f.dados[i]);
    }
    printf("]\n");  // fecha chaves
}

// Procedimento para adicionar elementos no final da fila
void fila_adicionar(struct fila *f, int val){
    /*
    (struct fila) *p [Ponteiro para uma fila]
    (int) val [Valor que será incerido na fila]
    */

    // Precisaremos usar passagem de parâmetros por referência
    // logo usaremos um ponteiro para a fila

    if (f->fim == tamanho){
        // Desvia o fim da lista para o índice 0
        f->fim = 0;
        f->dados[f->fim] = val; // Insere um valor no final da fila
        f->fim++; // Atualiza o valor de fim da fila
    }
    else{
        f->dados[f->fim] = val; // Insere um valor no final da fila
        f->fim++; // Atualiza o valor de fim da fila
    }
}

// Procedimento para remover elementos da fila
void fila_remover(struct fila *p){
    /*
    (struct fila) *p [Ponteiro para uma fila]
    */

    // Estrutura condicional que verifica
    // se a fila está vazia:
    if (p->fim == p->inicio){
        printf("\nfila vazia!\n");
    }
    // Se não está, podemos remover elementos:
    else{
        // Precisaremos usar passagem de parâmetros por referência
        // logo usaremos um ponteiro para a fila
        p->dados[p->fim-1] = 0;  // Remove o último elemento da fila
        p->fim--; // Atualiza o valor de fim da fila
    }
}

int main(){
    // Adicionar itens a fila
    fila_adicionar(&f1, 100);
    fila_adicionar(&f1, 200);
    fila_adicionar(&f1, 300);
    fila_adicionar(&f1, 400);

    // Imprimir fila
    fila_mostrar(f1);

    // Remover itens da fila
    fila_remover(&f1);
    fila_remover(&f1);
    fila_remover(&f1);
    fila_remover(&f1);

    // Imprimir fila
    fila_mostrar(f1);

    return 0;
}