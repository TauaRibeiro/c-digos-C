#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

struct pessoa{
    char nome[50], local[100];
    int idade;
};

int main(){
    system("cls");
    setlocale(LC_ALL, "Portuguese");

    struct pessoa pessoa;

    printf("Digite o seu nome: ");
    scanf(" %50[^\n]", pessoa.nome);
    printf("Digite a sua idade: ");
    scanf("%d", &pessoa.idade);
    printf("Digite a sua localidade: ");
    scanf(" %100[^\n]s", pessoa.local);
    system("cls");
    printf("NOME: %s\nIDADE: %d\nLOCALIDADE: %s", pessoa.nome, pessoa.idade, pessoa.local);
    return 0;
}
