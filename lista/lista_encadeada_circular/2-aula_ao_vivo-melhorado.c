#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/* Seguindo o conselho do professor, estou
melhorando o código que foi proposto na aula
ao vivo.*/



typedef struct LISTA{
    /* Estrutura lista-no
        int num; [Valor inteiro do nó]
        struct LISTA *prox; [ponteiro que aponta pra o próximo nó]
        struct LISTA *ant;  [ponteiro que aponta pra o nó anterior]
    */
    int num;
    struct LISTA *prox;
    struct LISTA *ant;  
}no;



typedef struct RetornoDuploDeNo{
    /* Estrutura para que funções possam retornar 2 valores do tipo
    ponteiro de nó
        no *re1 [Retorno1]
        no *re2 [Retorno2]
    */
    no *re1;
    no *re2;
}reDuplo;


// variável auxiliar
no *aux;


void ler_inicio_fim(inicio_l);

void imprime_menu(){
    system("cls");
    printf("\nMENU DE OPÇÕES\n");
    printf("\n1 - Inserir no inicio da lista");
    printf("\n2 - Inserir no fim da lista");
    printf("\n3 - Consultar a lista do inicio ao fim");
    printf("\n4 - Consultar a lista do fim ao inicio");
    printf("\n5 - Remover da lista");
    printf("\n6 - Esvaziar a lista");
    printf("\n7 - Sair");
    printf("\nDigite sua opcao: ");

}


reDuplo inserir_inicio(int val, no *inicio_l, no *fim_l){

    no *novo;
    novo = malloc(sizeof(no));
    novo->num = val;

    if (inicio_l == NULL){
        printf("\nNulo!\n");

        inicio_l = novo;
        fim_l = novo;
        novo->prox = inicio_l;
        novo->ant = inicio_l;
        //<- INICIO -> <- FIM ->

    }
    else{
        printf("\nNao nulo!\n"); 
        
        novo->prox = inicio_l;
        inicio_l->ant = novo;
        novo->ant = fim_l;
        fim_l->prox = novo;
        inicio_l=novo;
    }

    reDuplo retorno;
    retorno.re1 = inicio_l;
    retorno.re2 = fim_l;

    //ler_inicio_fim(inicio_l);

    return retorno;

}


reDuplo inserir_fim(int val, no *inicio_l, no *fim_l){

    no *novo = malloc(sizeof(no));

    novo->num = val;

    if (inicio_l == NULL){
        inicio_l = novo;
        fim_l = novo;
        novo->prox = inicio_l;
        novo->ant = inicio_l;
    }
    else{        
        fim_l->prox = novo;
        novo->ant = fim_l;        
        fim_l=novo;
        fim_l->prox = inicio_l;
        inicio_l->ant = fim_l;
    }

    reDuplo retorno;
    retorno.re1 = inicio_l;
    retorno.re2 = fim_l;
    return retorno;
}


void ler_inicio_fim(no *inicio_l){
    if (inicio_l == NULL){
        printf("\nLista vazia!!\n");
    }
    else{
        printf("\nConsultando a lista do inicio ao fim:\n");
        aux = inicio_l;
        do{
            printf("%d\n", aux->num);
            aux = aux->prox;
        }while (aux != inicio_l);
    }

}

void ler_fim_inicio(no *fim_l){
    if (fim_l == NULL){
        printf("\nLista vazia!!\n");
    }
    else{
        printf("\nConsultando a lista do fim ao inicio\n");
        aux = fim_l;
        do{
            printf("%d\n", aux->num);
            aux = aux->ant;
        }while (aux != fim_l);
    }
}


void remover(int val, no *inicio_l, no *fim_l){
    int achou;

    if (inicio_l == NULL){
        printf("\nLista vazia!!\n");
    }
    else{
        
        aux = inicio_l;
        achou = 0;
        int quantidade = 0;

        // Contabiliza o número de elementos da lista
        do{
            quantidade++;
            aux = aux->prox;
        }while (aux != inicio_l);
        int elemento = 1;

        do{
            if (inicio_l == fim_l && inicio_l->num == val){
                inicio_l = NULL;
                free(inicio_l);
                achou++;
            }
            else{
                if (aux->num == val){
                    achou++;
                    if (aux == inicio_l){
                        inicio_l = aux->prox;
                        inicio_l->ant = fim_l;
                        fim_l->prox = inicio_l;
                        free(aux);
                        aux = inicio_l;
                    }
                    else if(aux == fim_l){
                        fim_l = fim_l->ant;
                        fim_l->prox = inicio_l;
                        inicio_l->ant = fim_l;
                        free(aux);
                        aux = NULL;
                    }
                    else{
                        aux->ant->prox = aux->prox;
                        aux->prox->ant = aux->ant;
                        no *aux2;
                        aux2 = aux;
                        aux = aux->prox;
                        free(aux2);
                    }
                }
                else{
                aux = aux->prox;
                }
            }
            elemento++;
        }while(elemento <= quantidade);
        if (achou == 0)
            printf("\nNúmero não encontrado\n");
        else if (achou == 1)
            printf("\nNúmero removido 1 vez\n");
        else
            printf("\nNúmero removido %d vezes\n", achou);
    }

    
}


// Variáveis ----
// inicio e fim da lista
no *inicio = NULL;
no *fim = NULL;

// Opção de menu e valor inteiro
int opt, valor;

int main() {

    reDuplo var_retorno;


    do{ 
        imprime_menu();
        scanf("%d", &opt);

        switch (opt){
        case 1:
            printf("\nDigite o numero a ser inserido no inicio da lista: \n");
            scanf("%d", &valor);

            var_retorno = inserir_inicio(valor, inicio, fim);
            inicio = var_retorno.re1;
            fim = var_retorno.re2;
        
            printf("\nNumero inserido no inicio da lista.\n");

            if(inicio == NULL)
                printf("\ninicio ainda e nulo\n");
            else
                printf("\ninicio NAO e mais nulo\n");
        
            break;
        
        case 2:
            printf("\nDigite o numero a ser inserido no fim da lista: \n");
            scanf("%d", &valor);

            var_retorno = inserir_fim(valor, inicio, fim);
            inicio = var_retorno.re1;
            fim = var_retorno.re2;

            printf("\nNúmero inserido no fim da lista.\n");
            break;

        case 3:
            ler_inicio_fim(inicio);
            break;

        case 4:
            ler_fim_inicio(fim);
            break;

        case 5:
            printf("\nDigite o elemento a ser removido: \n");
            scanf("%d", &valor);
            remover(valor, inicio, fim);
            break;

        case 6:
        if (inicio == NULL){
        printf("\nLista vazia!!\n");
        }
        else{
            aux = inicio;
            do{
                inicio = inicio->prox;
                free(aux);
                aux = inicio;
            }while (aux != fim);
            free(fim);
            inicio = NULL;
            printf("\nLista esvaziada.\n");
        }

        default:
            break;
        }

        system("pause");
    }while (opt!= 7);
}