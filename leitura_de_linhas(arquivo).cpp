//Vai ser necessário criar um arquivo txt antes, caso contrário não irá funcionar;
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>


int main(){
    setlocale(LC_ALL, "Portuguese");
    
	FILE *arquivo;
	
	char *nome = (char *)malloc(50*sizeof(char)), letra;
	int tamanho = 0;
	int num_linha = 0, caracteres = 0;
	
	printf("Digite o nome do arquivo com sua extensão (ex: teste.txt): ");
	
	while((letra = getchar()) != '\n'){
		nome[tamanho] = letra;
		
		tamanho++;
		
		if(tamanho >= 49){
			nome = (char *)realloc(nome, (tamanho+1)*sizeof(char));
		}
	}
	
	nome[tamanho] = '\0';
	
	if(tamanho < 50){
		nome = (char *)realloc(nome, (tamanho+1)*sizeof(char));
	}
	
	arquivo = fopen(nome, "r");
	
	free(nome);
	
	if(arquivo == NULL){
		printf("ERRO!! Não foi possível abrir o arquivo...");
	}
	else{
		while((letra = getc(arquivo)) != EOF){
			
			if(letra == '\n'){
				caracteres = 0;
			}
			if(letra != '\n' && letra != EOF && caracteres == 0){
				caracteres = 1;
				
				num_linha++;
			}
		}
		
		printf("O arquivo tem %d %s;", num_linha, (num_linha == 1) ? "linha" : "linhas");
	}
	fclose(arquivo);
	
	return 0;
}
