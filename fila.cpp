#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

struct elemento{
    int num;
    struct elemento *proximo;
};

typedef elemento elemento;

struct fila{
    elemento *inicio;
    elemento *fim;
};

typedef fila fila;

fila *criar(){
    fila *nova = (fila *)malloc(sizeof(fila));

    nova->inicio = NULL;
    nova->fim = NULL;

    return nova;
}

void inserir(fila *fi){
    elemento *novo = (elemento *)malloc(sizeof(elemento));

    printf("Digite um número para inserir na fila: ");
    scanf("%d", &novo->num);

    novo->proximo = NULL;

    if(fi->inicio == NULL){
        novo->proximo = NULL;

        fi->inicio = novo;
        fi->fim = novo;
    }
    else{
        fi->fim->proximo = novo;

        fi->fim = novo;
    }

    printf("Elemento inserido com sucesso!!\n");
}

void mostrar(fila *fi){
    if(fi->inicio == NULL){
        printf("Fila vazia...\n");

        return;
    }

    elemento *aux = fi->inicio;

    do{
        printf("%d ", aux->num);

        aux = aux->proximo;
    }while(aux != NULL);

    printf("\n");
}
void remover(fila *fi){
    if(fi->inicio == NULL){
        printf("Fila vazia...\n");

        return;
    }

    elemento *aux = fi->inicio;

    fi->inicio = fi->inicio->proximo;

    free(aux);

    printf("Elemento removido com sucesso!!\n");
}

void esvaziar(fila *fi){
    if(fi->inicio == NULL){
        printf("A fila está vazia...\n");

        return;
    }

    elemento *aux = fi->inicio;

    do{
        fi->inicio = aux->proximo;

        free(aux);

        aux = fi->inicio;
    }while(aux != NULL);

    printf("Lista esvaziada com sucesso!!\n");
}
int main(){
    setlocale(LC_ALL, "Portuguese");

    fila *fila = criar();

    int decisao;

    do{
        printf("1. Inserir\n2. Mostrar\n3. Remover\n4. Esvaziar\n5. Sair\n");
        printf("Insira o número da decisão desejada: ");
        scanf("%d", &decisao);

        system("cls");

        switch(decisao){
            case 1:
                inserir(fila);
            break;
            case 2:
                mostrar(fila);
            break;
            case 3:
                remover(fila);
            break;
            case 4:
                esvaziar(fila);
            break;
            case 5:
            break;
            default:
                printf("Escolha inválida...\n");
            break;
        }
    }while(decisao != 5);
    
    return 1;
}