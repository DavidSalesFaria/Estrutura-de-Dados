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

// void remover(no *p){
//     /*
//     Exclui o último elemento a ser inserido
//     na lista
    
//     no *p [Ponteiro de nó que aponta para o nó cabeça]
//     */

//     no *lixo; // Lixo
//     // Removemos o nó ------
//     // Passamos o endereço do nó que removeremos
//     // para o "lixo". Esse é o último nó a ser inserido
//     // ou seja, é o nó mais perto do nó cabeça.
//     lixo = p->prox;
//     // Fazemos o nó cabeça apontar para
//     // o que o nó que jogamos no lixo apontava
//     p->prox = lixo->prox;

//     // Limpamos o lixo
//     free(lixo);
// }


void remover2(int val, no *lista){
    /*Remove elementos de uma lista encadeada.
    */

    // Cria um ponteiro para guardar a posição
    // do nó atual antes de passar para o próximo
    no *atual;
    // Aloca memória dinamicamente
    atual = (no*) malloc(sizeof(no));

    // Laço que percorre os nós da lista----
    // (Enquanto o dado do nó atual, for diferente do dado buscado)
    while (lista->valor != val){

        // Se o próximo nó da lista for NULL
        if(lista->prox == NULL){
            break; // Interrompa
        }

        // Guardamos a posição do nó atual
        atual = lista;
        // Passamos para o próximo nó
        lista = lista->prox; 
    }

    // Se o dado do próximo nó for igual ao dado buscado:
    if (lista->valor == val){
        // Faço o ponteiro "proximo" do nó atual
        // apontar para o nó posterior ao nó que
        // desejamos remover. Dessa forma, 
        // removemos o nó que queremos remover
        atual->prox = lista->prox;
    }

}


void imprimir(no *lista){
    /*
    Imprime a lista
    
    no *lista [Ponteiro de nó que aponta para o nó cabeça da lista]
    */
    // Ponteiro para leitura
    no *p;

    // Loop ----
    // (Enquanto o próximo nó da lista não for nulo)
    // Printa os dados dos nós lista
    while(lista->prox != NULL){
        // Printa o dado do nó atual
        printf("%d, ", lista->valor);
        // Passa para o próximo nó
        lista = lista->prox;
    }
    // OBS: O laço será interrompido antes de 
    // printar o dado do último nó, por isso
    // será necessário o printf adicional abaixo:
    printf("%d\n", lista->valor);
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
    remover2(36, le);

    // Imprime a lista
    imprimir(le);

    // Liberação de memória
    free(le);

return 0;
} 