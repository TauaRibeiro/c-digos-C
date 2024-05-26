#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

struct estoque{
    char nome[50];
    int quant;
    float preco;
};

void cadastro(struct estoque *e, int *p, int *q, int qtd);

int main(){
    system("cls");
    setlocale(LC_ALL, "Portuguese");

    struct estoque *produto;
    int qtd, maior_preco, maior_qtd;

    printf("Digite quantos produtos serão cadastrados: ");
    scanf("%d", &qtd);

    produto = (struct estoque *)malloc(qtd * sizeof(struct estoque));

    cadastro(produto, &maior_preco, &maior_qtd, qtd);

    for(int i = 0; i < qtd; i++){
        printf("NOME: %s\nQUANTIDADE: %d\nPREÇO: R$ %.2f\n", produto[i].nome, produto[i].quant, 
        produto[i].preco);

        printf("-----------------------------------------------\n");
    }

    printf("O produto com maior quantidade em estoque é o %s\n", produto[maior_qtd].nome);
    printf("O produto com maior preço em estoque é o %s", produto[maior_preco].nome);

    free(produto);
    return 0;
}

void cadastro(struct estoque *e, int *p, int *q, int qtd){
    for(int i = 0; i < qtd; i++){
        printf("Digite o nome do %d° produto: ", i+1);
        scanf(" %49[^\n]", e[i].nome);

        printf("Digite a quantidade: ");
        scanf("%d", &e[i].quant);

        printf("Digite o preço: R$ ");
        scanf("%f", &e[i].preco);

        if(i == 0){
            *p = i;
            *q = i;
        }else{
            if(e[i].quant> e[*q].quant){
                *q = i;
            }

            if(e[i].preco > e[*p].preco){
                *p = i;
            }
        }
        system("cls");
    }
}
