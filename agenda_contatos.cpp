//Ainda em construção
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <locale.h>
#include <time.h>
#include <string.h>

struct agenda{
    int mes, ano;
    char telefone[18], nome[100];
};

void gravacao(FILE **a, struct agenda *c, int qtd);
int inicializacao(FILE **a, struct agenda **c);
void cadastro(struct agenda **c, int indice);
void remocao(struct agenda **c, int qtd);
void linha(const char *tipo, int tamanho);
void procura(struct agenda *c, char nome[], int qtd);

int main(){
    system("cls");
    setlocale(LC_ALL, "Portuguese");

    FILE *arquivo;
    struct agenda *contato;
    char nome[100];
    int decisao, qtd_contatos;
    int loop = 0;

    qtd_contatos = inicializacao(&arquivo, &contato);

    do{
        do{
            linha("=-", 25);
            printf("ESCOLHA UMA DAS OPÇÕES ABAIXO:");
            linha("-", 30);
            printf("1- Inserir contato;\n2- Remover contato;\n3- Pesquisar contato;\n");
            printf("4- Listar contatos;\n5- Imprimir aniversário do mês;\n6- Sair;");
            linha("-", 30);
            printf("Digite o número da opção desejada: ");
            scanf("%d", &decisao);

            if(decisao <= 6 && decisao >= 1){
                linha("=-", 25);

                break;
            }

            system("cls");

            printf("Escolha inválida!!! Tente novamente;");
        }while(1);
        
        switch(decisao){
            case 1:
                cadastro(&contato, qtd_contatos-1);
                
                qtd_contatos++;

                gravacao(&arquivo, contato, qtd_contatos);

                printf("Cadastro realizado com sucesso!!");

            break;
            case 2:
            	remocao(&contato, qtd_contatos);
            	
            	qtd_contatos--;
            	
            	gravacao(&arquivo, contato, qtd_contatos);
            	
            	printf("Remoção realizada com sucesso!!!");
            break;
            case 3:
            	printf("Digite o nome da pessoa a procurar");
            	scanf(" %99[^\n]", nome);
            	
            	procura(contato, nome, qtd_contatos);
            break;
            case 6:
            	printf("ok");
            	loop = 0;
            break;
        }
    }while(loop);

    return 0;
}

void linha(const char *tipo, int tamanho){
    printf("%c", '\n');

    for(int i = 0; i < tamanho; i++){
        printf(tipo);
    }

    printf("%c", '\n');
}

void cadastro(struct agenda **c, int indice){
    int veri_data(int mes, int ano);
    int veri_telefone(char telefone[]);

    char nome[100], telefone[20];
    int mes, ano;
    int achou_erro, erro_telefone, erro_data;

    do{
        achou_erro = erro_data = erro_telefone = 0;

        linha("-", 30);
        printf("Digite o nome da pessoa: ");
        fscanf(stdin ," %99[^\n]", nome);

        fflush(stdin);
        
        linha("-", 30);
        printf("Digite o número de telefone de %s [(xx) x xxxx-xxxx]: ", nome);
        fscanf(stdin, " %17[^\n]", telefone);

        fflush(stdin);

        linha("-", 30);
        printf("Digite o mês e ano qm que %s faz aniversário (mm/aaaa): ", nome);
        scanf("%d/%d", &mes, &ano);

        system("cls");
        
        if(!veri_data(mes, ano)){
            achou_erro = erro_data = 1;
        }
        if(!(veri_telefone(telefone))){
            achou_erro = erro_telefone = 1;
        }

        if(!achou_erro){
            break;
        }

        printf("ERRO!!\n");
        printf("%s",(erro_data) ? "\nData de aniversário inválida..." : "");
        printf("%s", (erro_telefone) ? "\nNúmero de telefone inválido..." : "");

    }while(1);
    
    for(int i = 0; i < strlen(nome); i++){
    	if(nome[i] == ' '){
    		nome[i] = '!';
		}
	}
	
	for(int i = 0; i < 16; i++){
		if(telefone[i] == ' '){
			telefone[i] = '!';
		}
	}

    (*c)[indice].ano = ano;
    (*c)[indice].mes = mes;
    strcpy((*c)[indice].nome, nome);
    strcpy((*c)[indice].telefone, telefone);

    (*c) = (struct agenda *)realloc((*c), (indice+2)*sizeof(struct agenda));
}

int veri_data(int mes, int ano){
    time_t t;
    time(&t);
    struct tm *tempo = localtime(&t);

    int ano_atual = tempo->tm_year + 1900;

    if(mes > 12 || mes < 1){
        return 0;
    }
    if(ano > ano_atual || ano <= 1824){
        return 0;
    }

    return 1;   
}

int inicializacao(FILE **a, struct agenda **c){
    char nome[100], telefone[12];
    int mes, ano;
    int qtd;
    
    (*a) = fopen("gravacao.txt", "r");
    
    if((*a) == NULL){
        fclose((*a));

        (*a) = fopen("gravacao.txt", "w");
        
        fprintf((*a), "%d", 1);

        (*c) = (struct agenda *)malloc(sizeof(struct agenda));
    }
    else{
        fscanf((*a), "%d", &qtd);
        
        (*c) = (struct agenda *)malloc(qtd*sizeof(struct agenda));

        if(qtd != 1){
            for(int i = 0; i < qtd; i++){
                fscanf((*a), "%s %s %d %d", nome, telefone, &mes, &ano);
                
                for(int i = 0; i < str){
				}

                strcpy((*c)[i].nome, nome);
                strcpy((*c)[i].telefone, telefone);
                (*c)[i].mes = mes;
                (*c)[i].ano = ano;
            }    
        }
    }

    fclose((*a));

    return qtd;
}

void gravacao(FILE **a, struct agenda *c, int qtd){
    (*a) = fopen("gravacao.txt", "w");

    fprintf((*a), "%d\n", qtd);

    for(int i = 0; i < qtd-1; i++){
        fprintf((*a), "%s %s %d %d\n", c[i].nome, c[i].telefone, c[i].mes, c[i].ano);
    }

    fclose((*a));
}

int veri_telefone(char telefone[]){
    if(strlen(telefone) != 16){
    	printf("COMPRIMENTO\n");
        return 0;
    }
    if(telefone[0] != '(' || telefone[3] != ')'){
        printf("PARENTESES\n");
		return 0;
    }
    if(telefone[11] != '-'){
        printf("HIFEN\n");
		return 0;
    }

    return 1;
}

void remocao(struct agenda **c, int qtd){
	char nome[100], comp_nome[100];
	int achou = 0;
	
	printf("Digite o nome do contato a ser removido: ");
	scanf(" %99[^\n]", nome);
	
	for(int i = 0; i < strlen(nome); i++){
		nome[i] = tolower(nome[i]);
	}
	
	for(int i = 0; i < qtd; i++){
		strcpy(comp_nome, (*c)[i].nome);
		
		for(int x = 0; i < strlen(comp_nome); i++){
			comp_nome[i] = tolower(comp_nome[i]);
		}
		
		if(strcmp(nome, comp_nome) == 0){
			if(qtd == 2){
				free((*c));
				
				(*c) = (struct agenda *)malloc(sizeof(struct agenda));
			}
			else{
				for(int x = i; x < qtd; x++){
					strcpy((*c)[x].nome, (*c)[x+1].nome);
					strcpy((*c)[x].telefone, (*c)[x+1].telefone);
					(*c)[x].mes = (*c)[x+1].mes;
					(*c)[x].ano = (*c)[x+1].ano;
				}
				
				(*c) = (struct agenda *)realloc((*c), qtd*sizeof(struct agenda));
			}
			
		}
	}
	
}

void procura(struct agenda *c, char nome[], int qtd){
	int achou = 0;
	
	for(int  i = 0; i < strlen(nome); i++){
		nome[i] = tolower(nome[i]);
	}
	
	for(int i = 0; i < qtd; i++){
		if(strcmp(nome, c[i].nome)){
			linha("=+", 25);
			printf("NOME: %s\nTELEFONE: %s\nDATA ANIVERSÁRIO: %.2d/%d", c[i].nome, c[i].telefone, c[i].mes, c[i].ano);
		}
	}
}

