#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <ctype.h>

int main(){
    system("cls");
    setlocale(LC_ALL, "PORTUGUESE");
    
    FILE *arquivo;
    char *linha;
    char letra;
    
    arquivo = fopen("arq.txt", "w+");
    
    if(arquivo == NULL){
               printf("ERRO!! Não foi possível abrir o arquivo...");
               return 0;           
    }
    
    printf("Digite um texto, caso queira terminar digite 0 no final do texto:\n\n");
    
    linha = (char *)malloc(sizeof(char));
             
    if(linha == NULL){
             printf("ERRO!!  Não foi possível alocar a memória...");
                      
             free(linha);
                      
             return 0;
    }
             
    while((letra = getchar()) != '\n'){
                 linha[0] = letra;
                          
                 linha = (char *)realloc(linha, (strlen(linha) + 1)*sizeof(char));
                          
                 if(letra == NULL){
                          printf("ERRO!! Não foi possível realocar a memória...");
                                   
                          free(linha);
                                   
                          return 0;
                 }
             
    strcat(letra, "\n\0");
             
    fprintf(arquivo, "%s", linha);
             
    free(linha);
    
    
    
    return 0;
}
