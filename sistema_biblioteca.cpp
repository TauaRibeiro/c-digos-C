#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
	char titulos[50][100], autor[50][100], procura[100];
    int ano[50], decisao, livre = 0, achou;

    do{
        achou = 0;
        printf("Escolha uma das opcoes abaixo:\n");
        printf("1-> Cadastrar;\n2-> Procurar;\n3-> Sair;\n");
        printf("Digite o numero da opcao escolhida: ");
        scanf("%d", &decisao);
        system("cls");

        switch(decisao){
            case 1 :
                printf("Digite o titulo do livro: ");
                scanf("%s", titulos[livre]);
                printf("Digite o nome do autor: ");
                scanf("%s", autor[livre]);
                printf("Digite o ano de publicacao do livro: ");
                scanf("%d", &ano[livre]);
                livre++;
                system("cls");
            break;
            case 2 :
                if(livre == 0){
                    printf("Nao ha livros cadastrados para procurar.\n");
                }
                else{
                    printf("Escolha o metodo de procura:\n");
                    printf("1-> Nome autor;\n2-> Titulo;\n");
                    printf("Digite o numero da sua escolha: ");
                    scanf("%d", &decisao);
                    switch(decisao){
                        case 1 :
                            printf("Digite o nome do autor: ");
                            scanf("%s", procura);
                            system("cls");
                            for(int i = 0; i < livre; i++){
                                if(strcmp(autor[i], procura) == 0){
                                    printf("Livro encontrado!\n");
                                    achou = 1;
                                }
                            }
                            if(achou == 0){
                                printf("Livro nao encontrado...\n");
                            }
                        break;
                        case 2 : 
                            printf("Digite o titulo do livro: ");
                            scanf("%s", procura);
                            system("cls");
                            for(int i = 0; i < livre; i++){
                                if(strcmp(titulos[i], procura) == 0){
                                    printf("Livro encontrado!\n");
                                    achou = 1;
                                }
                            }
                            if(achou == 0){
                                printf("Livro nao encontrado...\n");
                            }
                            
                            break;
                    }
                }
        }
    }while(decisao != 3 && livre < 50);

    return 0;
}
