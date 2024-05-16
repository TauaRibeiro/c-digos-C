#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <ctype.h>

#define num_livros 5

struct biblioteca{
    char titulo[num_livros][31], autor[num_livros][16], procura[30];
    int ano[num_livros];
};


void linha(char tipo);

int main(){
    system("cls");
    setlocale(LC_ALL, "PORTUGUESE");
    
    struct biblioteca livro;
    int achou = 0, index_livros[num_livros] = {0}, posicao = 0;

    for(int i = 0; i < num_livros; i++){
        printf("Digite o título do %d° livro (max: 30 caracteres): ", i+1);
        scanf(" %30[^\n]", livro.titulo[i]);

        printf("Digite o nome do autor (max: 15 caracteres): ");
        scanf(" %15[^\n]", livro.autor[i]);

        printf("Digite o ano de publicacao do livro: ");
        scanf("%d", &livro.ano[i]);

        system("cls");
    }

    printf("Digite o título do livro que deseja procurar: ");
    scanf(" %30[^\n]", livro.procura);
    system("cls");

    for(int i = 0; i < num_livros; i++)
    {
        if(strcmp(livro.procura, livro.titulo[i]) == 0){
            achou = 1;
            index_livros[posicao] = i;
            posicao++;
        }
    }

    linha('=');
    if(achou == 0){
        printf("Livro não encontrado...");
    }
    else{
        printf("Foi encontrado %d %s que %s a sua procura:\n\n", posicao, (posicao>1) ? "livros" : "livro",
        (posicao>1) ? "correspondem" : "correponde");

        for(int i = 0; i < posicao; i++){
            printf("TÍTULO: %s\nAUTOR: %s\nANO: %d", livro.titulo[index_livros[i]],
            livro.autor[index_livros[i]], livro.ano[index_livros[i]]);
            if(i < posicao-1){
                linha('-');
            }
        }
    }
    linha('=');

    return 0;
}

void linha(char tipo){
    switch(tipo){
    case '=':
	    printf("\n========================================================\n");
    break;
    case '-':
        printf("\n---------------------------------------------------------\n");
    break;
    }
}
