#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <ctype.h>
#include <string.h>
//DEFININDO A CONSTANTE "num_produtos" COM O SEU REPECTIVO VALOR;
#define num_produtos 5
//CRIAÇÃO DA ESTRUTURA DO TIPO ESTOQUE;
struct estoque{
    char nome[16];
    int codigo;
    int quantidade;
    float preco;
};

//PROTOTIPAGEM DAS FUNÇÕES;
void linha(char tipo, int comprimento);
void cadastro(struct estoque *e);
int pedido(struct estoque *e, int cd, int qtd);

int main(){
	system("cls");
	setlocale(LC_ALL, "");
    //DECLARAÇÕES DAS VARIÁVEIS;
    struct estoque produto [num_produtos];
    char erro[][50] = {"Poduto não encontrado;", "Quantidade maior que o estoque;"};
    int codigo, quantidade, index;
    //CHAMADA DA FUNÇÃO CADASTRO;
    cadastro(produto);
	//LEITURA DO CÓDIGO DO PRODUTO QUE ESTÁ SENDO PEDIDO;
    printf("Digite o código do produto que gostaria de pedir: ");
    scanf("%d", &codigo);
    //LEITURA DA QUANTIDADE DO PRODUTO QUE ESTÁ SENDO PEDIDO;
    do{

        printf("Digite a quantidade a ser pedida: ");
        scanf("%d", &quantidade);

    }while(quantidade <= 0);
    //CHAMADA DA FUNÇÃO PEDIDO;
    index = pedido(produto, codigo, quantidade);

    linha('=', 50);
    /*SAÍDA DE DADOS;
    CASO O INDEX SEJA POSITIVO OU ZERO-> IRÁ IMPRIMIR AS INFORMÇÕES DO PRODUTO ATUALIZADAS;
    CASO SEJA NEGATIVO-> IRÁ IMPRIMIR A RAZÃO DO ERRO OCORRER;*/
    if(index >= 0){

        printf("PEDIDO EFETUADO\n");
        printf("PRODUTO -> %s\nCÓDIGO -> %d\nPREÇO -> R$ %.2f\nQUANTIDADE -> %d",
        produto[index].nome, codigo, produto[index].preco, quantidade);
    }

    else{

        printf("Ocorreu um erro: %s", erro[-(index+1)]);
    
    }

    linha('=', 50);
	return 0;
}
//FUNÇÃO DE IMPRIMIR UMA LINHA;
void linha(char tipo, int comprimento){
	printf("\n");
	for(int i = 0; i < comprimento; i++){
		printf("%c", tipo);
	}
	printf("\n");
}
//FUNÇÃO PARA CADASTRAR CADA UM DOS PRODUTOS DIGITADOS;
void cadastro(struct estoque *e){
    for(int i = 0; i < num_produtos; i++){
        
        printf("Digite o nome do %d° produto: ", i+1);
        scanf(" %15[^\n]s", &(e + i)->nome);

        linha('-', 50);

        printf("Digite o código do produto: ");
        scanf("%d", &(e + i)->codigo);

        linha('-', 50);

        printf("Digite a quantidade do produto: ");
        scanf("%d", &(e + i)->quantidade);

        linha('-', 50);

        printf("Digite o preço do produto: R$ ");
        scanf("%f", &(e + i)->preco);

        system("cls");
    }
}
/*FUNÇÃO PARA VERIFICAR SE UM PEDIDO PODE SER EFETUADO;
CASO ESTEJA TUDO CERTO-> ATUALIZA AS INFOMAÇÕES DO PRODUTO E RETORNA O SEU INDEX;
CASO OCORRA UM ERRO-> RETORNA UM NÚMERO NEGATIVO;*/
int pedido(struct estoque *e, int cd, int qtd){
    int achou;

    for(int i = 0; i < num_produtos; i++){

        if(cd == (e + i)->codigo){
            
            achou = 1;
            
            if(qtd <= (e + i)->quantidade){

                (e + 1)->quantidade -= qtd;
                return i;
            }
            else{

                return -2;
            }

            break;
        }
        else{

            achou = 0;
        }
    }
    if(achou == 0){

        return -1;
    }
}
