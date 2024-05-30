//É necessário criar um arquivo antes, caso contrário irá dar erro.
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <locale.h>

void abertura(FILE **l);
void substituir(FILE *leitura, FILE **arq);

int main(){
    system("cls");
    setlocale(LC_ALL, "Portuguese");

    FILE *leitura = NULL, *arquivo = NULL;

    abertura(&leitura);

    if(leitura == NULL){
        printf("ERRO!! Não foi possível abrir o arquivo...");

        return 0;
    }

    arquivo = fopen("substituicao.txt", "w");

    substituir(leitura, &arquivo);

    fclose(leitura);
    fclose(arquivo);
    
    return 0;
}

void abertura(FILE **l){
    char *nome = (char *)malloc(50*sizeof(char)), letra;
    int tamanho = 0;

    if(nome == NULL){
        printf("ERRO!! Não foi possível alocar memória...");

        exit(0);
    }

    printf("Digite o nome do arquivo e sua extensão(ex: exemplo.txt): ");

    while((letra = getchar()) != '\n'){
        nome[tamanho] = letra;

        tamanho++;

        if(tamanho >= 50){
            nome = (char *)realloc(nome, (tamanho + 1)*sizeof(char));

            if(nome == NULL){
                printf("ERRO!! Não foi possível realocar a memória...");

                exit(0);
            }
        }
    }

    system("cls");

    nome[tamanho] = '\0';

    (*l) = fopen(nome , "r");

    free(nome);    
}

void substituir(FILE *leitura, FILE **arq){
    char letra;
    char vogais[] = "aeiou";
    int vogal;

    (*arq) = fopen("gravacao.txt", "w");

    if((*arq) == NULL){
        printf("ERRO!! Não foi possível abrir o arquivo...");

        exit(0);
    }

    while((letra = getc(leitura)) != EOF){
        vogal = 0;

        for(int i = 0; i < 5; i++){
            if(tolower(letra) == vogais[i]){
                vogal = 1;

                fprintf((*arq), "%c", '*');
            }
        }

        if(!vogal){
            fprintf((*arq), "%c", letra);
        }
    }

}
