#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

struct no{
    int num;
    struct no *esquerda, *direita;
};

typedef struct no no;

struct arvore{
    no *raiz;
};

typedef struct arvore arvore;

arvore *criarArvore(){
    arvore *nova = (arvore *)malloc(sizeof(arvore));

    nova->raiz = NULL;

    return nova;
}

void inserir(arvore *arv){
    no *novo = (no *)malloc(sizeof(no));

    printf("Digite um n�mero para inserir na �rvore: ");
    scanf("%d", &novo->num);

    novo->direita = NULL;
    novo->esquerda = NULL;
    
    if(arv->raiz == NULL){
        arv->raiz = novo;
    }
    else{
        no *aux = arv->raiz;

        do{
            if(novo->num < aux->num){
                if(aux->esquerda == NULL){
                    aux->esquerda = novo;

                    break;
                }
                else{
                    aux = aux->esquerda;
                }
            }
            else{
                if(aux->direita == NULL){
                    aux->direita = novo;

                    break;
                }
                else{
                    aux = aux->direita;
                }
            }
        }while(1);
    }

    printf("N�mero inserido com sucesso!!\n");
}

void consultar(arvore *arv){
    if(arv->raiz == NULL){
        printf("N�o h� elementos inseridos...\n");

        return;
    }

    int num_consulta;

    printf("Digite o n�mero que deseja consultar: ");
    scanf("%d", &num_consulta);

    no *aux = arv->raiz;

    do{
        if(num_consulta == aux->num){
            printf("N�mero encontrado!!\n");

            return;
        }
        else if(num_consulta < aux->num){
            aux = aux->esquerda;
        }
        else{
            aux = aux->direita;
        }
    }while(aux != NULL);

    printf("N�mero n�o encontrado...\n");
}
/*
1- galho esquerdo
2- raiz
3- galho direito*/

void ordem(arvore *arv, no *ramo){
    if(arv->raiz == NULL){
        printf("�rvore vazia...\n");

        return;
    }

    if(ramo == NULL){
        return;
    }

    ordem(arv, ramo->esquerda);

    printf("%d ", ramo->num);

    ordem(arv, ramo->direita);
}
/*
1- raiz
2- galho esquerdo
3- galho direito*/
void pre_ordem(arvore *arv, no *ramo){
    if(arv->raiz == NULL){
        printf("�rvore vazio...\n");

        return;
    }

    if(ramo == NULL){
        return;
    }

    printf("%d ", ramo->num);

    pre_ordem(arv, ramo->esquerda);

    pre_ordem(arv, ramo->direita);
}
/*
1- galho esquerdo
2- galho direito
3 raiz*/
void pos_ordem(arvore *arv, no *ramo){
    if(arv->raiz == NULL){
        printf("�rvore vazia...\n");

        return;
    }

    if(ramo == NULL){
        return;
    }

    pos_ordem(arv, ramo->esquerda);

    pos_ordem(arv, ramo->direita);

    printf("%d ", ramo->num);
}

void remocao(arvore *arv){
    if(arv->raiz == NULL){
        printf("�rvore vazia...\n");

        return;
    }

    no *atual = arv->raiz;
    no *pai = NULL;
    no *filho;
    no *sucessor, *pai_sucessor;

    int num_remocao;

    printf("Digite o n�mero a ser eliminado: ");
    scanf("%d", &num_remocao);

    while(atual != NULL && atual->num != num_remocao){
        pai = atual;

        if(num_remocao < atual->num){
            atual = atual->esquerda;
        }
        else{
            atual = atual->direita;
        }
    }

    if(atual == NULL){
        printf("N�mero n�o encontrado...\n");

        return;
    }

    //Liberando folha;
    if(atual->direita == NULL && atual->esquerda == NULL){
        if(atual == arv->raiz){
            arv->raiz = NULL;
        }
        else if(pai->esquerda == atual){
            pai->esquerda = NULL;        
        }
        else{
            pai->direita = NULL;
        }

        free(atual);
    }//remove n� com apenas um filho
    else if(atual->direita == NULL || atual->esquerda == NULL){
        if(atual->esquerda != NULL){
            filho = atual->esquerda;
        }
        else{
            filho = atual->direita;
        }

        if(atual == arv->raiz){
            arv->raiz = filho;
        }
        else if(pai->esquerda == atual){
            pai->esquerda = filho;
        }
        else{
            pai->direita = filho;
        }

        free(atual);
    }//remove n� com dois filhos
    else{
        sucessor = atual->direita;
        pai_sucessor = atual;

        while(sucessor->esquerda != NULL){
            pai_sucessor = sucessor;

            sucessor = sucessor->esquerda;
        }

        atual->num = sucessor->num;

        if(pai_sucessor->esquerda == sucessor){
            pai_sucessor->esquerda = sucessor->direita;
        }
        else{
            pai_sucessor->direita = sucessor->direita;
        }

        free(sucessor);
    }

    printf("N�mero deletado com sucesso!!\n");
}

void esvaziar(arvore *arv, no *ramo){
    if(arv->raiz == NULL){
        printf("A �rvore est� vazia...\n");

        return;
    }

    if(ramo == NULL){
        return;
    }

    esvaziar(arv, ramo->esquerda);

    esvaziar(arv, ramo->direita);

    free(ramo);    
}

int main(){
    system("cls");
    setlocale(LC_ALL, "Portuguese");

    arvore *arvore = criarArvore();

    int escolha;

    do{
        printf("1. Inserir\n");
        printf("2. Consultar n�\n");
        printf("3. Consultar em ordem\n");
        printf("4. Consultar em pr�-ordem\n");
        printf("5. Consultar em p�s-ordem\n");
        printf("6. Remover n�\n");
        printf("7. Esvaziar n�\n");
        printf("8. Sair\n");
        printf("Digite o n�mero da op��o desejada: ");
        scanf("%d", &escolha);

        system("cls");

        switch(escolha){
            case 1:
                inserir(arvore);
            break;
            case 2:
                consultar(arvore);
            break;
            case 3:
                ordem(arvore, arvore->raiz);

                printf("\n");
            break;
            case 4:
                pre_ordem(arvore, arvore->raiz);

                printf("\n");
            break;
            case 5:
                pos_ordem(arvore, arvore->raiz);

                printf("\n");
            break;
            case 6:
                remocao(arvore);

                printf("N�mero removido com sucesso!!\n");
            break;
            case 7:
                esvaziar(arvore, arvore->raiz);

                arvore->raiz = NULL;

                printf("�rvore esvaziada com sucesso!!\n");
            break;
            case 8:
                printf("FIM");
            break;
            default:
                printf("Escolha inv�lida, tente novamente...\n");
            break;
        }
    }while(escolha != 8);

    return 1;
}