//Ainda em construção
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <locale.h>
#include <time.h>
#include <string.h>

struct agenda{
    int mes, ano;
    char telefone[15], nome[];
};

int leitura(FILE **a, struct agenda **c);
void cadastro(struct agenda **c, int indice);
void remocao(struct arquivo[]);
void linha(const char *tipo, int tamanho);

int main(){
    system("cls");
    setlocale(LC_ALL, "Portuguese");

    FILE *arquivo;
    struct agenda *contato;
    int decisao, qtd_contatos;
    int fim = 0;

    arquivo = fopen("gravacao.txt", "r");
    
    if(arquivo == NULL){
        fclose(arquivo);

        arquivo = fopen("gravacao.txt", "w");
        
        fprintf(arquivo, "%d", 1);

        contato = (struct agenda *)malloc(sizeof(struct agenda));
    }
    else{
        qtd_contatos = leitura(&arquivo, &contato);
    }

    fclose(arquivo);

    do{
        do{
            linha("=-", 25);
            printf("ESCOLHA UMA DAS OPÇÕES ABAIXO:");
            linha("-", 30);
            printf("1- Inserir contato;\n2- Remover contato;\n3- Pesquisar contato;\n");
            printf("4- Listar contatos;\n5- Imprimir aniversário do mês;");
            linha("-", 30);
            printf("Digite o número da opção desejada: ");
            scanf("%d", &decisao);

            if(decisao <= 5 && decisao >= 1){
                linha("=-", 25);

                break;
            }

            system("cls");

            printf("Escolha inválida!!! Tente novamente;");
        }while(1);
        
        switch(decisao){
            case 1:
                cadastro(&arquivo, &contato, qtd_contatos-1);
                
                qtd_contatos++;

                printf("Cadastro realizado com sucesso!!");
            break;
        }
    }while(fim);

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

    char nome[100], telefone[15];
    int mes, ano;
    int achou_erro, erro_telefone, erro_data;

    do{
        achou_erro = erro_data = erro_telefone = 0;

        linha("-", 30);
        printf("Digite o nome da pessoa: ");
        fscanf(stdin ," %99[^\n]", nome);

        fflush(stdin);
        
        linha("-", 30);
        printf("Digite o número de telefone de %s (+55xxxxxxxxxxx): ", nome);
        fscanf(stdin, " %14[^\n]", telefone);

        fflush(stdin);

        linha("-", 30);
        printf("Digite o mês e ano qm que %s faz aniversário (mm/aaaa): ", nome);
        scanf("%2d/%d", &mes, &ano);

        system("cls");
        
        if(!veri_data(mes, ano)){
            achou_erro = erro_data = 1;
        }
        if(!(strlen(telefone) == 14)){
            achou_erro = erro_telefone = 1;
        }

        if(!achou_erro){
            break;
        }

        printf("ERRO!!\n");
        printf("%s",(erro_data) ? "\nData de aniversário inválida..." : "");
        printf("%s", (erro_telefone) ? "\nNúmero de telefone inválido..." : "");

    }while(1);

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

int leitura(FILE **a, struct agenda **c){
