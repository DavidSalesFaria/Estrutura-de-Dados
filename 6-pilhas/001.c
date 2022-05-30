#include <stdio.h>
#include <stdlib.h>

/*Em uma estrutura de dados pilha, 
o último elemento a entrar é o primeiro a sair*/

// Constante
#define tamanho 3
// Estrutura pilha
struct pilha{
    /*
    (int) dados[tamanho] [Vetor que irá conter os dados
    da pilha]
    (int) inicio [Valor inteiro que aponta para o início da pilha]
    (int) topo [Valor inteiro que  aponta para a primeira
    posição disponível da pilha, ou seja o topo da pilha]
    */

    int dados[tamanho];  // dados da pilha
    int inicio; // inicio da pilha
    int topo; // topo da pilha
};


// Procedimento para mostrar o conteúdo da Pilha
void pilha_imprimir(struct pilha p){
    int i;
    printf("\n["); // abre chaves
    // Laço para imprimir todos os valores da pilha
    for (i=0; i<tamanho; i++){
        // Estrutura condicional para formatar
        // a impresssão [val1, val2, ...val3]
        if(i+1 < tamanho)
            printf("%d, ", p.dados[i]);
        else
            printf("%d", p.dados[i]);
    }
    printf("]\n");  // fecha chaves
}

// Procedimento para adicionar elementos no final da pilha (EMPILHAR)
int push(struct pilha *p, int val){
    /*
    (struct pilha) *p [Ponteiro para uma pilha]
    (int) val [Valor que será incerido na pilha]
    return (int) [Retorna -1 se a pilha estiver cheia e 0 se não estiver]
    */

    // Estrutura condicional que 
    // Verifica se a pilha está cheia
    if (p->topo == tamanho){
        printf("\nPilha esta cheia!\n");
        return -1;
    }
    // Se não está, podemos inserir elementos
    else{
        // Precisaremos usar passagem de parâmetros por referência
        // logo usaremos um ponteiro para a pilha
        p->dados[p->topo] = val; // Insere um valor no final da pilha
        p->topo++; // Atualiza o valor de topo da pilha
        return 0;
    }
}

// Procedimento para remover elementos da pilha (DESEMPILHAR)
int pop(struct pilha *p){
    /*
    (struct pilha) *p [Ponteiro para uma pilha]
    return (int) removido [Valor removido da pilha]
    */

    int removido; // Recebe o valor que será removido

    // Estrutura condicional que verifica
    // se a pilha está vazia:
    if (p->topo == p->inicio){
        printf("\nPilha vazia!\n");
        return -1;
    }
    // Se não está, podemos remover elementos:
    else{
        // Precisaremos usar passagem de parâmetros por referência
        // logo usaremos um ponteiro para a pilha
        removido = p->dados[p->topo-1]; // Elemento a ser removido da pilha
        p->dados[p->topo-1] = 0;  // Remove o último elemento da pilha
        p->topo--; // Atualiza o valor de topo da pilha
        return removido;     
    }
}


struct pilha p1;
int valores[4] = {100, 200, 300, 400}; 
int removidos[4], i, retorno;

int main(){

    // Adiciona itens na pilha
    for (i=0; i<4; i++){
        retorno = push(&p1, valores[i]);
        // Se a função retornar -1 então
        // a pilha está cheia
        if (retorno == -1){
            break;
        }
    }

    // Imprimir pilha
    pilha_imprimir(p1);

    // Remover itens da pilha
    for (i=0; i<4; i++){
        retorno = pop(&p1);

        // Verifica se a função não retornou -1
        // Se retornou é por que a lista está vazia
        if(retorno == -1){
            break;
        }
        // Senão a lista não está vazia
        else{
            removidos[i] = retorno;
        }
    }
    
    // Imprimir pilha
    pilha_imprimir(p1);

    printf("\nValores removidos (OS ZEROS nao CONTAM):\n");
    for (i=0; i<5; i++){ 
       printf("% d", removidos[i]);
    }
    printf("\n\n");

    return 0;
}