#include <stdio.h>
#include <stdlib.h>

// AULA 5 [UPDADE NO CÓDIGO]
//[VAMOS APRENDER A ENCONTRAR ELEMENTOS DA NOSSA ÁRVORE BINÁRIA]

typedef struct no{
    int conteudo;
    struct no *esquerda, *direita;
}No;

// PROTOTIPOS
void inserirEsquerda(No *no, int valor);
void inserirDireita(No *no, int valor);

void inserirEsquerda(No *no, int valor){
    /*Função que insere um nó FILHO à esquerda de um nó PAI
    fazendo chamadas recursivas até encontrar um nó FILHO à esquerda NULL (vazio)
    ou até 'valor' ser maior que o conteúdo do nó FILHO à esquerda
    nesse caso, chama a função inserirDireita

    Observe que temos 2 codições de parada:
     1ª O nó FILHO à esquerda é NULL:
        Nesse caso 'valor' será inserido nesse nó FILHO à esquerda.

     2º 'valor' é maior que o conteúdo do nó FILHO à esquerda:
        Nesse caso chamaremos a função inserirDireita() encerrando
        as chamadas recursivas desta função.
    
    (No) *no [Nó PAI que receberá um FILHO caso não tenha]
    (int) valor [Valor que será inserido no novo nó que será criado]
    */

    // Se o nó PAI não tiver FILHO à esquerda, então
    // vamos criar esse filho.
    // OBS: Esse if-else(if-else) utiliza de chamadas recursivas
    // em que a 1ª condição de parada se encontra nesse primeiro if,
    // A 2ª condição de parada no else mais interno.
    if (no->esquerda == NULL){
        // Cria dinamicamente, um novo nó: 
        // OBS: novo->conteudo equivale à (*novo).conteudo
        No *novo = (No*) malloc(sizeof(No));
        // Insere o valor
        novo->conteudo = valor; 
        // Inicialmente, o novo nó criado não tem filho à esquerda nem à direita
        novo->esquerda = NULL; 
        novo->direita = NULL;
        // Atribuímos esse novo nó como FILHO esquerdo do nó PAI.
        no->esquerda = novo;
    }
    // Senão, o nó PAI tem sim um FILHO a esquerda, então
    // vamos inserir um nó FILHO nesse FILHO
    else{

        // Se 'valor' for menor que o conteúdo do FILHO à esquerda, então
        // vamos inserir um nó FILHO à esquerda desse nó
        if (valor < no->esquerda->conteudo){
            // <<CHAMADA RECURSIVA>>
            inserirEsquerda(no->esquerda, valor);
        }
        // Senão, se 'valor' é maior que o conteúdo do FILHO à esquerda, então
        // vamos inserir um nó FILHO à direita desse nó
        else if (valor < no->esquerda->conteudo){
            inserirDireita(no->esquerda, valor);
        }
        else{
            printf("ERRO! Valor duplicado!");
        }
    }
}

void inserirDireita(No *no, int valor){
    /*Função que insere um nó FILHO à direita de um nó PAI
    fazendo chamadas recursivas até encontrar um nó FILHO à direita NULL (vazio)
    ou até 'valor' ser menor que o conteúdo do nó FILHO à direita,
    nesse caso, chama a função inserirEsquerda.

    Observe que temos 2 codições de parada:
     1ª O nó FILHO à direita é NULL:
        Nesse caso 'valor' será inserido nesse nó FILHO à direita.

     2º 'valor' é menor que o conteúdo do nó FILHO à direita:
        Nesse caso chamaremos a função inserirEsquerda() encerrando
        as chamadas recursivas desta função.
    
    (No) *no [Nó PAI que receberá um FILHO caso não tenha]
    (int) valor [Valor que será inserido no novo nó que será criado]
    */

    // Se o nó PAI não tiver FILHO à direita, então
    // vamos criar esse filho.
    // OBS: Esse if-else(if-else) utiliza de chamadas recursivas
    // em que a 1ª condição de parada se encontra nesse primeiro if,
    // A 2ª condição de parada no else mais interno.
    if (no->direita == NULL){
        // Cria dinamicamente, um novo nó:
        // OBS: novo->conteudo equivale à (*novo).conteudo
        No *novo = (No*) malloc(sizeof(No));
        // Insere o valor
        novo->conteudo = valor; 
        // Inicialmente, o novo nó criado não tem filho à esquerda nem à direita
        novo->esquerda = NULL; 
        novo->direita = NULL;
        // Atribuímos esse novo nó como FILHO direito do nó PAI.
        no->direita = novo;
    }
    // Senão, o nó PAI tem sim um FILHO a direita, então
    // vamos inserir um nó FILHO nesse FILHO
    else{
        // Se 'valor' for maior que o conteúdo do FILHO à direita, então
        // vamos inserir um nó FILHO à direita desse nó
        if (valor > no->direita->conteudo){
            // <<CHAMADA RECURSIVA>>
            inserirDireita(no->direita, valor);
        }
        // Senão, 'valor' é menor que o conteúdo do FILHO à direita, então
        // vamos inserir um nó FILHO à esquerda desse nó
        else if (valor > no->direita->conteudo){
            inserirEsquerda(no->direita, valor);
        }
        else{
            printf("ERRO! Valor duplicado!");
        }
    }
}

No* inserir(No *raiz, int valor){
    if(raiz == NULL){
        // Cria dinamicamente, um novo nó: 
        // OBS: novo->conteudo equivale à (*novo).conteudo
        No *novo = (No*) malloc(sizeof(No));
        // Inserimos o valor
        novo->conteudo = valor; 
        // Inicialmente, o novo nó criado não tem filho à esquerda nem à direita
        novo->esquerda = NULL; 
        novo->direita = NULL;
        return novo;
    }
    else{
        if(valor < raiz->conteudo){
            raiz->esquerda = inserir(raiz->esquerda, valor);
        }
        else if(valor > raiz->conteudo){
            raiz->direita = inserir(raiz->direita, valor);
        }
        return raiz;
    }

}

int tamanho(No *raiz){
    /*
    Retorna o tamanho de uma árvore binária
    fazendo uso de chamadas recursivas
    */

    // Se o nó for núlo:
    if(raiz == NULL){
        return 0; // Retorna 0
    }
    // Senão
    else{
        // <<CHAMADAS RECURSIVAS>>
        // Retorna o tamanho da subárvore esquerda e o tamanho
        // da subárove direita + 1 (que representa o nó raíz)
        return 1 + tamanho(raiz->esquerda) + tamanho(raiz->direita);
    }
}

int buscar(No *raiz, int chave){
    /*
        Realiza a busca de um elemento em uma
        árvore binária, se este elemento for encontrado
        , retorna 1, senão, retorna 0.
    */

   // Se o nó for nulo
   if(raiz == NULL){
       return 0;
   }
   // Senão
    else{
        
        // Se o conteúdo da raíz for igual à chave
        // então retorna 1
        if (raiz->conteudo == chave){
            return 1;
        }
        // Senão
        else{
            // <<CHAMADAS RECURSIVAS>>
            // Se a chave for menor que o conteúdo da raíz
            if(chave < raiz->conteudo)
                // Buscar a chave na árvore esquerda
                return buscar(raiz->esquerda, chave);

            // Senão, se a chave for maior que o conteúdo da raíz
            else if(chave > raiz->conteudo)
                // Buscar a chave na árvore direita
                return buscar(raiz->direita, chave);        
        }
    }
}

void imprimir(No *raiz){
    /*
        Imprime a árvore binária na tela
        fazendo chamadas recursivas
    */

    // Se a raíz não é nula
    if (raiz != NULL){
        // Imprime a subárvore esquerda
        imprimir(raiz->esquerda);
        // Imprime o valor da raíz
        printf("%d ", raiz->conteudo);
        // Imprime a subárvore direita
        imprimir(raiz->direita);
    }
}

int main(){
    // Variáveis
    int opt; // Opções do meno
    int valor; // Valor para os nós
    //ArvB arv; // Árvore
    // A raíz da nossa árvore é NULL inicialmente
    //arv.raiz = NULL;

    No *raiz = NULL;

    do{
        printf("\n0 - sair\n1 - inserir\n2 - imprimir\n3 - tamanho\n4 - Buscar\n");
        scanf("%d", &opt);

        switch(opt){
        case 0:
            system("cls");
            printf("\nSaindo...\n");
            break;

        case 1:
            system("cls");
            printf("\nDigite um valor: ");
            scanf("%d", &valor);
            printf("\n%d\n", valor);
            //inserir(&arv, valor);
            raiz = inserir(raiz, valor);
            break;

        case 2:
            system("cls");
            printf("\nImpressao da arvore binaria:\n");
            imprimir(raiz);
            break;

        case 3:
            system("cls");
            printf("\nNumero de nos: %d\n", tamanho(raiz));
            break;

        case 4:
            system("cls");
            printf("Buscar elemento: ");
            scanf("%d", &valor);
            printf("\nRetorno: %d\n", buscar(raiz, valor));
            break;

        default:
            system("cls");
            printf("\nOpção invalida!\n");
            break;
        }

    }while(opt != 0);

    return 0;
}