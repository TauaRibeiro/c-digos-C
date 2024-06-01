//Será necessário criar dois arquivos antes, caso contrário irá dar erro;
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <locale.h>

void abertura(FILE **a, const char *tipo);
void gravar(FILE *l, FILE **j);

int main(){
    system("cls");
    setlocale(LC_ALL, "Portuguese");

    FILE *leitura1, *leitura2;
    FILE *juncao = fopen("gravacao.txt", "w");

    if(juncao == NULL){
        printf("ERRO!! Não foi possível abrir/criar o arquivo \'gravacao.txt\'");

        return 0;
    }

    abertura(&leitura1, "r");
    abertura(&leitura2, "r");

    gravar(leitura1, &juncao);
    gravar(leitura2, &juncao);

    fclose(leitura1);
    fclose(leitura2);
    fclose(juncao);
    
 
    return 0;
}

int num_arquivo = 1;

void abertura(FILE **a, const char *tipo){
    char *nome = (char *)malloc(50*sizeof(char)), letra;
    int tamanho = 0;

    printf("Digite o nome do %d° arquivo com sua extensão (ex: exemplo.txt): ", num_arquivo++);

    while((letra = getchar()) != '\n'){
        nome[tamanho] = letra;

        tamanho++;

        if(tamanho >= 50){
            nome = (char *)realloc(nome, (tamanho+1)*sizeof(char));
        }
    }
    
    nome[tamanho] = '\0';

    if(tamanho < 49){
        nome = (char *)realloc(nome, tamanho*sizeof(char));
    }

    (*a) = fopen(nome, tipo);

    if((*a) == NULL){
        printf("ERRO!! Não foi possível abrir o arquivo %s...", nome);

        free(nome);
        exit(0);
    }

    free(nome);
}

void gravar(FILE *l, FILE **j){
    char letra;

    while((letra = getc(l)) != EOF){
        fprintf((*j), "%c", letra);
    }
}
