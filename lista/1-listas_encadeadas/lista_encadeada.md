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

Vamos inicializar o nosso nó cabeça 'le' (lista encadeada) na nossa função main, lembrando que é uma variável do tipo 'no'. Vamos zerar o valor do nó e como é o primeiro nó da lista, inicialmente, o seu ponteiro 'prox' não aponta para nada.
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
**Ilustração:**<br>
[Clique aqui](https://youtu.be/ZU3imaXbdTk) E assista esse vídeo que ilustra a inserção de valores em uma lista encadeada.



**Vamos chamar o procedimento de inserção na nossa função main e inserir alguns valores na lista:**
```C
inserir(30, le);
inserir(20, le);
```

OBS: Como o nó cabeça apontava para NULL, o primeiro nó a ser inserido na lista apontará para NULL também e conforme formos inserindo mais nós, o primeiro nó a entrar na lista ficará no último lugar.


## Percorrer

Já criamos e adicionamos valores à nossa lista, agora vamos percorre-la e printar todos os valores inseridos.

```C
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
    while(lista->proximo != NULL){
        // Printa o dado do nó atual
        printf("%d, ", lista->dado);
        // Passa para o próximo nó
        lista = lista->proximo;
    }
    // OBS: O laço será interrompido antes de 
    // printar o dado do último nó, por isso
    // será necessário o printf adicional abaixo:
    printf("%d\n", lista->dado);
}
```


**Ilustração:**<br>
[Clique aqui](https://youtu.be/is7emG01YDs) E assista esse vídeo que ilustra o percorrer uma lista encadeada.


## Remoção

Sabemos como adicionar valores depois do nó cabeça. Vamos fazer algo um pouco diferente com o procedimento de remoção. Vamos que o procedimento possa remover qualquer elemento da lista.

O procedimento abaixo tem um laço que percorre a lista, e quando encontra o nó com o valor buscado, remove o nó.

```C
void remover(int val, no *lista){
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
```


**Ilustração:**<br>
[Clique aqui](https://youtu.be/8nKdvdua4Vw) E assista esse vídeo que ilustra a remoção de um elemento de uma lista encadeada.


**Referências:**

Site:
https://www.ime.usp.br/~pf/algoritmos/aulas/lista.html
