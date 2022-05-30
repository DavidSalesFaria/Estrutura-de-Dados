# Listas Encadeadas, inserir, percorrer e remover


Uma lista encadeada é uma representação de uma sequência de objetos, todos do mesmo tipo, na memória RAM do computador. Cada elemento da sequência é armazenado em um nó da lista: o primeiro elemento na primeiro nó, o segundo no segundo, e assim por diante.

Diferentemente de um vetor, os elementos de uma lista não estão ordenados na memória, porém cada nó tem um ponteiro que aponta para o próximo nó da lista, dessa forma, podemos percorrer a lista ordenadamente.



Cada nó da lista será formado por 2 itens, são eles o valor do nó e um ponteiro que aponta para o próximo nó.
```C
typedef struct lista{
    // Conteúdo do nó
    int valor;
    // Ponteiro para o próximo nó
    struct lista *prox;
}no;
```

## Criação
Para criar uma lista encadeada, primeiro precisamos criar um nó cabeça. Este nó,  aponta para o começo da nossa lista, portanto ele é muito importante.

Vamos inizializar o nosso nó cabeça na nossa função main, lembrando que é uma variável do tipo 'no'. Vamos zerar o valor do nó e como é o primeiro nó da lista, inicialmente, o seu ponteiro 'prox' não aponta para nada.
```C
no *le; 
// Alocação dinâmica de memória
le = (no*) malloc(sizeof(no));
le->valor = 0;
le->prox = NULL;
```

## Inserção

Agora vamos ver como inserir valores em uma lista. Podemos criar um procedimento para essa operação.

Saiba que não existe uma regra específica para inserir valores em uma lista encadeada. Nesse nosso caso, vamos sempre inserir um novo nó logo após o nó cabeça.

```C
void inserir(int val, no *p){
    /*
    int val [Valor que será inserido no nó]
    no *p [Ponteiro de nó que aponta para o nó cabeça]
    */

    // Criação do novo nó por
    // Alocação dinâmica
    no *novo;
    novo = malloc(sizeof(no));
    // Inserimos o valor do nó
    novo->valor = val;
    // Inserimos o nó na lista:
        // Fazemos o novo nó apontar para oque o
        // nó cabeça apontava e fazemos
        // o nó cabeça apontar para o novo nó:
        // noX -> noZ
        // nox -> noNovo -> noZ
    novo->prox = p->prox;
    p->prox = novo;

}
```

OBS: Como o nó cabeça apontava para NULL, o primeiro nó a ser inserido na lista apontará para NULL também e conforme formos inserindo mais nós, o primeiro nó a entrar na lista ficará no último lugar.

Assista esse vídeo que ilustra a inserção de valores em uma lista encadeada.

[![Texto](Estrutura-de-Dados/lista/1-listas_encadeadas/imagens/video1.png)](https://youtu.be/ZU3imaXbdTk)


Referências:

Site:
https://www.ime.usp.br/~pf/algoritmos/aulas/lista.html
