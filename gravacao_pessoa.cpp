/*Será necessário criar antes um arquivo que contenha os seguintes dados na mesma linha
nome(podendo ser completo) data de nascimento(MM/AAAA)*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <locale.h>

void abrir(FILE **a, const char *tipo);
void gravar(FILE *l, FILE **g);

int main(){
    system("cls");
    setlocale(LC_ALL, "Portuguese");
    
    FILE *leitura, *gravacao;

    printf("Digite o nome do arquivo de leitura(exemplo.txt): ");
    abrir(&leitura, "r");
    
    printf("Digite o nome do arquivo de gravação(exemplo.txt): ");
    abrir(&gravacao, "w");

    gravar(leitura, &gravacao);

    printf("Gravação feita com sucesso!!");

    fclose(leitura);
    fclose(gravacao);
    return 1;
}

void abrir(FILE **a, const char *tipo){
    char *nome = (char *)malloc(50*sizeof(char));
    char letra;
    int tamanho = 0;

    if(nome == NULL){
        printf("ERRO!! Não possível alocar memória...");

        free(nome);
        exit(0);
    }

    while((letra = getchar()) != '\n'){
        nome[tamanho++] = letra;

        if(tamanho >= 50){
            nome = (char *)realloc(nome, (tamanho+1)*sizeof(char));

            if(nome == NULL){
                printf("ERRO!! Não foi possível realocar mais memória...");

                free(nome);
                exit(0);
            }
        }
    }

    if(tamanho < 49){
        nome = (char *)realloc(nome, tamanho*sizeof(char));

        if(nome == NULL){
            printf("ERRO!! Não foi possível realocar a memória exata....");

            free(nome);
            exit(0);
        }
    }

    nome[tamanho] = '\0';

    (*a) = fopen(nome, tipo);

    if((*a) == NULL){
        printf("ERRO!! Não foi possível abrir o arquivo \'%s\'...", nome);

        free(nome);
        
        exit(0);
    }

    free(nome);
}

void gravar(FILE *l, FILE **g){
    time_t tempo;
    char *nome = (char *)malloc(50*sizeof(char));
    char caracter;
    int mes, ano, tamanho = 0;

    time(&tempo);
    
    fprintf((*g), "%s\n", ctime(&tempo));

    while((caracter = getc(l)) != EOF){
        if(isdigit(caracter) == 0 && caracter != '\n'){
            nome[tamanho++] = caracter;

            if(tamanho >= 50){
                nome = (char *)realloc(nome, (tamanho+1)*sizeof(char));
            }    
        }
        else if(isdigit(caracter) != 0){
            nome[tamanho] = '\0';

            fscanf(l, "%d/%d", &mes, &ano);
            fprintf((*g), "NOME: %s\nDATA NASCIMENTO: %.2d/%d\n\n", nome, mes, ano);

            tamanho = 0;
            free(nome);
            nome = (char *)malloc(50*sizeof(char)); 
        }
        
    }
}
