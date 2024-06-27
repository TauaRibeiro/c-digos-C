#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

struct no{
    char nome[30];
    float salario;

    no *proximo;
    no *anterior;
};

typedef no no;

struct lista{
    no *inicio;
    no *fim;
};

typedef lista lista;

lista *criar(){
    lista *nova = (lista*)malloc(sizeof(lista));

    nova->inicio = NULL;
    nova->fim = NULL;

    return nova;
}

void inserir(lista *l, int quant){
    no *novo_funcionario = (no*)malloc(sizeof(no));

    printf("Digite o nome do %d funcionário: ", quant);
    scanf(" %29[^\n]s", novo_funcionario->nome);

    printf("Digite o salário de %s: R$ ", novo_funcionario->nome);
    scanf("%f", &novo_funcionario->salario);

    if(l->inicio == NULL){
        novo_funcionario->proximo = NULL;
        novo_funcionario->anterior = NULL;

        l->inicio = novo_funcionario;
        l->fim = novo_funcionario;
    }
    else{
        no *aux = l->inicio;

        while(aux != NULL && aux->salario > novo_funcionario->salario){
            aux = aux->proximo;
        }

        if(aux == NULL){
            novo_funcionario->proximo = NULL;
            novo_funcionario->anterior = l->fim;

            l->fim->proximo = novo_funcionario;
            l->fim = novo_funcionario;
        }
        else if(aux->anterior == NULL){
            novo_funcionario->anterior = NULL;
            novo_funcionario->proximo = l->inicio;

            l->inicio->anterior = novo_funcionario;
            l->inicio = novo_funcionario;
        }
        else{
            novo_funcionario->proximo = aux;
            novo_funcionario->anterior = aux->anterior;

            aux->anterior->proximo = novo_funcionario;
            aux->anterior = novo_funcionario;
        }
    }

    system("cls");
}

void MaiorSalario(lista *l){
    no *aux = l->inicio->proximo;

    int contador = 1;
    float maior = l->inicio->salario;

    do{
        if(aux->salario > maior){
            maior = aux->salario;

            contador = 1;
        }

        if(maior == aux->salario){
            contador++;
        }

        aux = aux->proximo;
    }while(aux != NULL);

    aux = l->inicio;

    if(contador == 1){
        printf("O funcionário com o maior salário é:\n\n");
    }
    else{
        printf("Os funcionários com os maiores salários são:\n\n");
    }

    do{
        if(aux->salario == maior){
            printf("NOME: %s\nSALÁRIO: R$ %.2f\n\n", aux->nome, aux->salario);
        }

        aux = aux->proximo;
    }while(aux != NULL);
}

float MediaSalarial(lista *l){
    no *aux = l->inicio;

    float media = 0;

    do{
        media += aux->salario;

        aux = aux->proximo;
    }while(aux != NULL);

    media /= 8;

    return media;
}

int contagem(lista *l, float compara){
    int contador = 0;

    no *aux = l->inicio;

    do{
        if(aux->salario > compara){
            contador++;
        }

        aux = aux->proximo;
    }while(aux != NULL);

    return contador;
}

int main(){
    system("cls");
    setlocale(LC_ALL, "Portuguese");

    lista *lista = criar();
    
    float analise;
    int quantidade;

    for(int i = 1; i < 4; i++){
        inserir(lista, i);
    }
    
    MaiorSalario(lista);

    printf("Digite o slarário de analise: R$ ");
    scanf("%f", &analise);

    quantidade = contagem(lista, analise);

    if(quantidade == 0){
        printf("Não há nenhum funcionário com salário acima de R$ %.2f", analise);
    }
    else{
        printf("Há %d %s com salário acima de R$ %.2f", quantidade, (quantidade == 1) ? "funcionário" : 
        "funcionários", analise);
    }
    return 1;
}