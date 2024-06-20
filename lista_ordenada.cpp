#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

struct no{
	int idade;
	char nome[30];
	no *anterior;
	no *proximo;
};

typedef no no;

struct lista{
	no *inicio;
	no *fim;
};

typedef lista lista;

no *aux;

lista *criar(){
	lista *novo = (lista *)malloc(sizeof(lista));
	
	novo->inicio = NULL;
	novo->fim = NULL;
	
	return novo;
}

void adicionar(lista * l){
	no *novo = (no *)malloc(sizeof(no));
	
	printf("Digite um nome: ");
	scanf(" %29[^\n]s", novo->nome);
	
	printf("Agora digite a idade de \'%s\': ", novo->nome);
	scanf("%d", &novo->idade);
	
	if(l->inicio == NULL){
		l->inicio = novo;
		l->fim = novo;
		
		novo->proximo = NULL;
		novo->anterior = NULL;
	}
	else{
		aux = l->inicio;
		
		while(aux != NULL && aux->idade < novo->idade){
			aux = aux->proximo;
		}
		
		if(aux == l->inicio){
			novo->proximo = l->inicio;
			novo->anterior = NULL;
			
			l->inicio->anterior = novo;
			l->inicio = novo;
		}
		else if(aux == NULL){
			l->fim->proximo = novo;
			
			novo->anterior = l->fim;
			novo->proximo = NULL;
			
			l->fim = novo;
		}
		else{
			novo->proximo = aux;	
			novo->anterior = aux->anterior;
					
			aux->anterior->proximo = novo;
			aux->anterior = novo;
		}
	}
	
	printf("Adicionado com sucesso!!\n");
}

void imprimir(lista *l){
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
int main(){
	setlocale(LC_ALL, "Portuguese");
	
	lista *lista = criar();
	
	int opcao;
	do{
		printf("1- Adicionar\n2- Remover\n3- Exibir\n");
		printf("4- Procurar\n5- Esvaziar\n6- Sair\n");
		printf("Digite o número da opção desejada: ");
		scanf("%d", &opcao);
		
		system("cls");
		
		switch(opcao){
			case 1:
				adicionar(lista);
			break;
			case 3:
				imprimir(lista);
			break;
			case 6:
			break;
			default:
			break;
		}
	}while(opcao != 6);
	
	
}
