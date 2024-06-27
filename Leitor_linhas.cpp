#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

int main(){
    system("cls");
    setlocale(LC_ALL, "Portuguese");

    char *texto;
    char *linha;
    char letra;
    int tamanho, total_taman = 0, primeiro = 1;

    printf("Digite um texto qualquer;\n");
    printf("Caso queira terminar apenas aperte ENTER para finalinalizar;\n\n");

    texto = (char *)malloc(sizeof(char));

    texto[0] = '\0';

    while(1){
        linha = (char *)malloc(sizeof(char));
        tamanho = 0;
        while((letra = getchar())){
            linha[tamanho] = letra;

            tamanho++;

            linha = (char *)realloc(linha, (tamanho + 1)*sizeof(char));
            
            if(letra == '\n'){
                break;
            }
        }

        linha[tamanho] = '\0';

        if(tamanho ==  1 && linha[0] == '\n'){
            free(linha);

            break;    
        }
        else{
            total_taman += tamanho;
            
            texto = (char *)realloc(texto, total_taman*sizeof(char));
            if(primeiro){
                strcpy(texto, linha);

                primeiro = 0;    
            }
            
            else{
                strcat(texto, linha);
            }

            free(linha);
        }
    }

    system("cls");

    printf("%s", texto);

    free(texto);
    return 0;
}