#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>
//Definição da estrutura livro;
struct livro{
    char titulo[21], autor[21];
    int ano;
};
//Definição da estrutura biblioteca;
struct biblioteca{
    int livre;
    struct livro livro[50];
};
//Prototipagem das fuções;
void cadastro(struct biblioteca *b);
int procura(struct biblioteca *b, int metodo);
void linha(char tipo, int comprimento);

int main(){
    system("cls");
    setlocale(LC_ALL, "Portuguese");
    //Declaração das variáveis e inicialização da varaiável livre como 0;
    struct biblioteca sistema;
    int decisao, index;
    sistema.livre = 0;
    
    do{
        index  = 0;

        linha('=', 50);
        //Menu principal do sistema;
        printf("Escolha uma das opções abaixo:\n");
        printf("1-> Cadastrar;\n2-> Procurar;\n3-> Sair;\n");
        printf("Digite o número da opção escolhida: ");
        scanf("%d", &decisao);
        
        linha('=', 50);
    
        switch(decisao){
            //Cadastrar um livro;
            case 1 :
                cadastro(&sistema);
            break;
            /*Procurar um livro;
            Caso não haja livros cadastrados, irá mostrar que não livros para procurar;
            Caso contrário irá msostrar o menu de procura;*/
            case 2 :
                if(sistema.livre == 0){
                    system("cls");
                    printf("Não há livros cadastrados para procurar.\n");
                }
                //Menu de procura;
                else{
                    printf("Escolha o método de procura:\n");
                    printf("1-> Nome do autor;\n2-> Título;\n");
                    printf("Digite o número da sua escolha: ");
                    scanf("%d", &decisao);

                    index = procura(&sistema, decisao);
                    
                    system("cls");
                    /*Saída do resultado da procura;
                    Caso seja positivo ou zero, irá mostrar as informações do livro procurado;
                    Caso contrário, irá mostrar que o livro não foi encontrado;*/
                    if(index >= 0){
                        printf("Livro encontrado!!\n");
                        printf("TÍTULO-> %s\nAUTOR-> %s\nANO-> %d", sistema.livro[index].titulo,
                        sistema.livro[index].autor, sistema.livro[index].ano);

                    }
                    else{
                        printf("Livro não encontrado...");
                    }
                }
            break;
        }
    }while(decisao != 3 && sistema.livre < 50);

    return 0;
}
//Função responsável por cadastrar um livro;
void cadastro(struct biblioteca *b){
    int livre = b->livre;

    printf("Digite o titulo do livro: ");
    scanf(" %20[^\n]", b->livro[livre].titulo);
    
    linha('-', 50);
    
    printf("Digite o nome do autor: ");
    scanf(" %20[^\n]", b->livro[livre].autor);
    
    linha('-', 50);
    
    printf("Digite o ano de publicacao do livro: ");
    scanf("%d", &b->livro[livre].ano);
    
    b->livre++;
}
/*Função responsável por procurar um livro no sistema;
Caso encontre, irá retornar o index do livro;
Caso contrário, irá retornar -1;*/
int procura(struct biblioteca *b, int metodo){
    char compara[20];

    linha('-', 50);

    printf("Digite o %s: ", (metodo == 1) ? "nome do autor" : "título da obra");
    scanf(" %20[^\n]", compara);

    switch(metodo){
        case 1 : 
            for(int i = 0; i < 50 - (b->livre); i++){
                if(strcmp(b->livro[i].autor, compara) == 0){
                    return i;
                }
            }
        break;

        case 2 :
            for(int i = 0; i < 50 - (b->livre); i++){
                if(strcmp(b->livro[i].titulo, compara) == 0){
                    return i;
                }
            }
        break;
    }
    return -1;
}
//Função responsável por imprimir uma linha formatada;
void linha(char tipo, int comprimento){
    printf("\n");

    for(int i = 0; i < comprimento; i++){
        printf("%c", tipo);
    }

    printf("\n");
}
