#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/*Lista encadeada na aula ao vivo*/

typedef struct lista{
    // Conteúdo do nó
    int valor;
    // Ponteiro para o próximo nó
    struct lista *prox;
}no;


void inserir(int val, no *p){
    /*
    Insere um novo nó na lista endadeada.
    A inserção é feita logo após o nó cabeça,
    logo, o nó cabeça sempre será o primeiro nó
    da lista e a leitura da lista será feita apartir
    do último valor inserido até o primeiro.

    int val [Valor que será inserido no nó]
    no *p [Ponteiro de nó que aponta para o nó cabeça]
    */

    // Criação do novo nó por
    // Alocação dinâmica
    no *novo;
    novo = malloc(sizeof(no));
    // Conteúdo do nó
    novo->valor = val;
    // Inserimos o nó na lista:
        // Fazemos novo nó apontar para oque o
        // nó anterior apontava e fazemos
        // o nó anterior apontar para o novo nó:
        // noX -> noZ
        // nox -> noNovo -> noZ
    novo->prox = p->prox;
    p->prox = novo;

}

void excluir(no *p){
    /*
    Exclui o último elemento a ser inserido
    na lista
    
    no *p [Ponteiro de nó que aponta para o nó cabeça]
    */

    no *lixo; // Lixo
    // Removemos o nó ------
    // Passamos o endereço do nó que removeremos
    // para o "lixo". Esse é o último nó a ser inserido
    // ou seja, é o nó mais perto do nó cabeça.
    lixo = p->prox;
    // Fazemos o nó cabeça apontar para
    // o que o nó que jogamos no lixo apontava
    p->prox = lixo->prox;

    // Limpamos o lixo
    free(lixo);
}

void imprimir(no *le){
    /*
    Imprime a lista
    
    no *le [Ponteiro de nó que aponta para o nó cabeça]
    */
    // Ponteiro para leitura
    no *p;

    // Laço para percorrer a lista:
    // Percorre a lista fazendo p começar pelo
    // nó cabeça e enquanto p não for NULL
    // o laço pass para o próximo nó (p = p->prox) 
    for (p = le; p!=NULL; p = p->prox){
        printf("%d, ", p->valor);
    }
    printf("\n");
}


int main(){
    // ------Variáveis-----
    int i, valor;
    // Inizializar Nó cabeça__________
    no *le; 
    le = (no*) malloc(sizeof(no));
    // O nó cabeça conteúdo zerado
    le->valor = 0;
    // O nó cabeça, não aponta
    // para nada inicialmente
    le->prox = NULL;
    // ________________________________

    valor = 6;
    // Inserir múltiplos de 6
    for(i = 1; i<=10; i++){
        inserir(valor*i, le);
    }

    // Exclui o último elemento
    // a entrar na lista, neste caso, 60.
    excluir(le);

    // Imprime a lista
    imprimir(le);

    // Liberação de memória
    free(le);

return 0;
} 