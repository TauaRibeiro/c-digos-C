#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

struct elemento{
    int num;
    struct elemento *proximo;
};

typedef elemento elemento;

struct pilha{
    struct elemento *topo;
};

typedef pilha pilha;

pilha *criar(){
    pilha *nova = (pilha *)malloc(sizeof(pilha));

    nova->topo = NULL;

    return nova; 
}

void inserir(pilha *pi){
    elemento *novo = (elemento *)malloc(sizeof(elemento));

    printf("Digite um número para inserir na pillha: ");
    scanf("%d", &novo->num);

    novo->proximo = pi->topo;
    pi->topo = novo;

    printf("Número inserido com sucesso!!\n");
}

void mostrar(pilha *pi){
    if(pi->topo == NULL){
        printf("Pilha vazia...\n");

        return;
    }

    elemento *aux = pi->topo;

    do{
        printf("%d ", aux->num);

        aux = aux->proximo;
    }while(aux != NULL);

    printf("\n");
}

void deletar(pilha *pi){
    if(pi->topo == NULL){
        printf("Pilha vazia...\n");

        return;
    }

    elemento *aux = pi->topo;

    pi->topo = pi->topo->proximo;

    free(aux);

    printf("Elemento do topo deletado com sucesso!!\n");
}

void esvazia(pilha *pi){
    if(pi->topo == NULL){
        printf("A pilha já está vazia...\n");

        return;
    }

    elemento *aux = pi->topo;

    do{
        pi->topo = aux->proximo;

        free(aux);

        aux = pi->topo;
    }while(aux != NULL);

    printf("Pilha esvaziada com sucesso!!\n");
}

int main(){
    system("cls");
    setlocale(LC_ALL, "Portuguese");

    pilha *pilha = criar();

    int decisao;

    do{
        printf("1. Inserir\n2. Mostrar pilha\n3. Remover topo\n4. Esvaziar pilha\n5. Sair\n");
        printf("Digite o número da opção desejada: ");
        scanf("%d", &decisao);

        system("cls");

        switch(decisao){
            case 1:
                inserir(pilha);
            break;
            case 2:
                mostrar(pilha);
            break;
            case 3:
                deletar(pilha);
            break;
            case 4:
                esvazia(pilha);
            break;
            case 5:
            break;
            default:
                printf("Opção inválida...\n");
            break;
        }
    }while(decisao != 5);

    return 1;
}