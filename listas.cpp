#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>

#define MAX_CARACTERES 30

struct no{
    char nome[MAX_CARACTERES];
    int idade;
    no *proximo;
    no *anterior;
};

typedef no no;

struct lista{
    no *inicio;
    no *fim;
};

typedef lista lista;

no *aux;
no *temp;

lista *criar(){
    lista *novo = (lista *)malloc(sizeof(lista));

    novo->inicio = NULL;
    novo->fim = NULL;

    return novo;
}

void adicionar(lista *l){
    no *novo = (no *)malloc(sizeof(no));

    printf("Digite o nome a ser adicionado na lista: ");
    scanf(" %29[^\n]s", novo->nome);

    printf("Digite a idade de %s: ", novo->nome);
    scanf("%d", &novo->idade);

    if(l->inicio == NULL){
        novo->anterior = NULL;
        novo->proximo = NULL;

        l->inicio = novo;
        l->fim = novo;
    }
    else{
        aux = l->inicio;

        while(aux != NULL && aux->idade < novo->idade){
            aux = aux->proximo;
        }

        if(aux == NULL){
            novo->proximo = NULL;
            novo->anterior = l->fim;

            l->fim->proximo = novo;
            l->fim = novo;
        }
        else if(aux->anterior == NULL){
            novo->proximo = l->inicio;
            novo->anterior = NULL;

            l->inicio->anterior = novo;
            l->inicio = novo;
        }
        else{
            novo->anterior = aux->anterior;
            novo->proximo = aux;

            aux->anterior->proximo = novo;
            aux->anterior = novo;
        }
    }

    printf("Inserido com sucesso!!\n");
}

void mostrar(lista *l){
    if(l->inicio == NULL){
        printf("Lista vazia...\n");

        return;
    }

    aux = l->inicio;

    do{
        printf("NOME: %s\nIDADE: %d\n\n", aux->nome, aux->idade);

        aux = aux->proximo;
    }while(aux != NULL);
}

void deletar(lista *l){
    char nome[MAX_CARACTERES], compara[MAX_CARACTERES];
    int idade, escolha, achou = 0;

    if(l->inicio == NULL){
        printf("Lista vazia...\n");

        return;
    }

    aux = l->inicio;

    printf("Escolha um dos métodos para deletar:\n");
    printf("1. Nome\n2. Idade\n");
    printf("Digite o número de uma opção: ");
    scanf("%d", &escolha);

    switch(escolha){
        case 1:
            printf("Digite o nome a ser deletado: ");
            scanf(" %29[^\n]s", nome);

            for(int i = 0; nome[i] != '\0'; i++){
                nome[i] = tolower(nome[i]);
            }

            do{
                strcpy(compara, aux->nome);

                for(int i = 0; compara[i] != '\0'; i++){
                    compara[i] = tolower(compara[i]);
                }

                if(strcmp(compara, nome) == 0){
                    if(aux->anterior == aux->proximo){
                        l->fim = NULL;
                        l->inicio = NULL;
                    }
                    else if(aux->anterior == NULL){
                        l->inicio = aux->proximo;
                        
                        l->inicio->anterior = NULL;
                    }
                    else if(aux->proximo == NULL){
                        l->fim = l->fim->anterior;
                        
                        l->fim->proximo = NULL;
                    }
                    else{
                        aux->proximo->anterior = aux->anterior;
                        aux->anterior->proximo = aux->proximo;
                    }

                    temp = aux;

                    free(temp);

                    achou++;
                }

                aux = aux->proximo;
            }while(aux != NULL);
        break;
        case 2:
            printf("Digite a idade a ser removida: ");
            scanf("%d", &idade);

            do{
                if(aux->idade == idade){
                    if(aux->anterior == aux->proximo){
                        l->fim = NULL;
                        l->inicio = NULL;
                    }
                    else if(aux->anterior == NULL){
                        l->inicio = aux->proximo;
                        
                        l->inicio->anterior = NULL;
                    }
                    else if(aux->proximo == NULL){
                        l->fim = l->fim->anterior;
                        
                        l->fim->proximo = NULL;
                    }
                    else{
                        aux->proximo->anterior = aux->anterior;
                        aux->anterior->proximo = aux->proximo;
                    }


                    temp = aux;

                    free(temp);

                    achou++;
                }

                aux = aux->proximo;
            }while(aux != NULL);
        break;
        default:
            printf("Escolha inválida...\n");
        break;            
    }

    if(achou == 0){
        printf("Não foi encontrado nenhuma correspondência...\n");
    }
    else{
        printf("Foi encontrada %d %s!!\n", achou, (achou == 1) ? "correspondência" : "correspondências");
    }
}

void esvaziar(lista *l){
    if(l->inicio == NULL){
        printf("A lista já está vazia...\n");

        return;
    }

    aux = l->inicio->proximo;

    do{
        temp = aux;

        free(temp);

        aux = aux->proximo;
    }while(aux != NULL);

    l->inicio = NULL;
    l->fim = NULL;

    printf("Lista esvaziada com sucesso..\n");
}

int main(){
    system("cls");
    setlocale(LC_ALL, "Portuguese");

    lista *lista = criar();
    int decisao;
    do{
        printf("1. Inserir\n2. Mostrar lista\n");
        printf("3. Remover\n4. Esvaziar lista\n5. Sair\n");
        printf("Digite o número da sua escolha: ");
        scanf("%d", &decisao);

        system("cls");

        switch(decisao){
            case 1:
                adicionar(lista);
            break;
            case 2:
                mostrar(lista);
            break;
            case 3:
                deletar(lista);
            break;
            case 4:
                esvaziar(lista);
            break;
            case 5:
            break;
            default:
                printf("Opção inválida, tente novamente...\n");
            break;
        };
    }while(decisao != 5);
    
    return 1;
}

