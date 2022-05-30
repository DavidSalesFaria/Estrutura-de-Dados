#include <stdio.h>
#include <stdlib.h>

/*Em uma estrutura de dados fila, 
o primeiro elemento a entrar é o primeiro a sair*/

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

// Procedimento para mostrar o conteúdo da fila
void fila_imprimir(struct fila p){
    int i;
    printf("\n["); // abre chaves
    // Laço para imprimir todos os valores da fila
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

// Procedimento para adicionar elementos no final da fila
int push_back(struct fila *p, int val){
    /*
    (struct fila) *p [Ponteiro para uma fila]
    (int) val [Valor que será incerido na fila]
    return (int) [Retorna -1 se a pilha estiver cheia e 0 se não estiver]
    */

    // Estrutura condicional que 
    // Verifica se a fila está cheia
    if (p->fim == tamanho){
        printf("\nfila esta cheia!\n");
        return -1;
    }
    // Se não está, podemos inserir elementos
    else{
        // Precisaremos usar passagem de parâmetros por referência
        // logo usaremos um ponteiro para a fila
        p->dados[p->fim] = val; // Insere um valor no final da fila
        p->fim++; // Atualiza o valor de fim da fila
        return 0;
    }
}

// Procedimento para remover elementos da fila
int pop(struct fila *f){
    /*
    (struct fila) *p [Ponteiro para uma fila]
    return (int) retorno [Valor que foi removido da pilha
    se a pilha já estiver vazia o retorno será -1]
    */

    // Precisaremos usar passagem de parâmetros por referência
    // logo usaremos um ponteiro para a fila

    // Receberá o valor que será removido da lista
    // Inicializado com -1
    int removido = -1;

    // Estrutura condicional que verifica
    // se a fila está vazia:
    if (f->inicio == f->fim){
        printf("\nfila vazia!\n");
        return removido;
    }
    // Se não está, podemos remover elementos:
    else{

        removido = f->dados[f->inicio]; // Valor a ser removido

        // Laço para remover o primeiro elemento da fila
        // e reorganizar os que ficarem
        int i;
        for(i=0; i<tamanho; i++){
    
            // O elemento mais a esquerda receber
            // o valor do elemento mais a direita
            f->dados[i] = f->dados[i+1];
        }

        // Faz o fim da lista receber 0
        // OBS: Nos meus testes mesmo sem essa linha o código
        // funcionou bem, porém, pode ser que o professor
        // colocou essa linha no exemplo para evitar que
        // alguma parte do vetor fosse ocupada por lixo de memória
        f->dados[f->fim] = 0;

        f->fim--; // Atualliza o valor de fim
        
        return removido;
    }
}


struct fila f1;
int valores[4] = {100, 200, 300, 400}; 
int removidos[4], i, retorno;

int main(){
    // Adiciona itens na pilha
    for (i=0; i<4; i++){
        retorno = push_back(&f1, valores[i]);
        // Se a função retornar -1 então
        // a pilha está cheia
        if (retorno == -1){
            break;
        }
    }

    // Imprimir fila
    fila_imprimir(f1);

    // Remover itens da fila
    for (i=0; i<4; i++){
        retorno = pop(&f1);

        // Verifica se a função não retornou -1
        // Se retornou é por que a fila está vazia
        if(retorno == -1){
            break;
        }
        // Senão a fila não está vazia
        else{
            removidos[i] = retorno;
        }
    }
    
    // Imprimir fila
    fila_imprimir(f1);

    printf("\nValores removidos (OS ZEROS nao CONTAM):\n");
    for (i=0; i<5; i++){ 
       printf("% d", removidos[i]);
    }
    printf("\n\n");

    return 0;
}