#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <ctype.h>
#include <string.h>

#define num_produtos 2

struct estoque{
    char nome[16];
    int codigo;
    int quantidade;
    float preco;
};


void linha(char tipo, int comprimento){
	printf("\n");
	for(int i = 0; i < comprimento; i++){
		printf("%c", tipo);
	}
	printf("\n");
}

int main(){
	system("cls");
	setlocale(LC_ALL, "Portuguese");
    
    struct estoque produto [num_produtos];
    char tipo_erro[][50] = {"Poduto não encontrado;", "Quantidade maior que o estoque;"};
    int codigo, quantidade, achou, erro = 0, index;

    for(int i = 0; i < num_produtos; i++){
        
        printf("Digite o nome do %d° produto: ", i+1);
        scanf(" %15[^\n]s", produto[i].nome);

        linha('-', 50);

        printf("Digite o codigo do produto: ");
        scanf("%d", &produto[i].codigo);

        linha('-', 50);

        printf("Digite a quantidade do produto: ");
        scanf("%d", &produto[i].quantidade);

        linha('-', 50);

        printf("Digite o preoco do produto: R$ ");
        scanf("%f", &produto[i].preco);

        system("cls");
    }
	
    printf("Digite o código do produto que gostaria de pedir: ");
    scanf("%d", &codigo);

    do{

        printf("Digite a quantidade a ser pedida: ");
        scanf("%d", &quantidade);

    }while(quantidade <= 0);

    for(int i = 0; i < num_produtos; i++){

        if(codigo == produto[i].codigo){
            
            achou = 1;
            
            if(quantidade <= produto[i].quantidade){

                produto[i].quantidade -= quantidade;
                index = i;
            
            }

            else{

                erro = 2;

            }

            break;

        }

        else{

            achou = 0;
        
        }

    
    }
    
    if(achou == 0){

        erro = 1;
    
    }

    linha('=', 50);
    if(erro == 0){

        printf("PEDIDO EFETUADO\n");
        printf("PRODUTO -> %s\nCÓDIGO -> %d\nPRECO -> R$ %.2f\nQUANTIDADE -> %d",
        produto[index].nome, codigo, produto[index].preco, quantidade);
    }

    else{

        printf("Ocorreu um erro: %s", tipo_erro[erro-1]);
    
    }

    linha('=', 50);
	return 0;
} 
