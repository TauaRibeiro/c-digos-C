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
    int zero = 0, tamanho = 0, deci;
    
    do{
	    printf("Escolha a operação a ser feita:\n");
	    printf("1- Gravar arquivo;\n2- Ler arquivo;\n");
	    printf("Digite o número da sua escolha: ");
	    scanf("%d", &deci);
	    
	    system("cls");
	}while(deci > 2 || deci < 1);
	
	switch(deci){
		case 1 : 
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
		    
			while(!zero){
				do{
		    		letra = getchar();
		    		
					if(letra == '0'){
		    			zero = 1;
		    		
		    			break;
					}
					else{
		    			linha[tamanho] = letra;
				
		    			tamanho++;
		                
		    			linha = (char *)realloc(linha, (tamanho + 1)*sizeof(char));
		                        
		    			if(letra == NULL){
		        			printf("ERRO!! Não foi possível realocar a memória...");
		                              
		        			free(linha);
		                                   
		        			return 0;
		    			}
		    	
		    		}
		    	}while(letra != '0');
				
				linha[tamanho] = '\0';	
			}
		    
		    fprintf(arquivo, "%s", linha);
			
		    free(linha);
		
		break;
		case 2:
			arquivo = fopen("arq.txt", "r");
			
			while((letra = fgetc(arquivo)) != EOF){
				printf("%c", letra);
			}
		break;
	}
	
	fclose(arquivo);
    
    
    
    return 0;
}
