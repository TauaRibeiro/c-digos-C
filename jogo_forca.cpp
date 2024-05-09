#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>

int main() {
    system("cls");
    char letra, decisao;
    char palavras[5][20] = {{"SENAI"}, {"DIJUNTOR"}, {"MUNDO"}, {"MARCIO"}, {"VASCO"}}, display[20], palavra[20];
    int vidas, aleatorio, comprimento, achou, vitoria;
    
    do {
        srand(time(NULL));
        aleatorio = rand() % 5;
        vidas = 5;
        strcpy(palavra, palavras[aleatorio]);
        comprimento = strlen(palavra);
        for(int i = 0; i < 20; i++){
            display[i] = '?';
        }
        
        while(1){
            achou = 0;
            vitoria = 1;
            for(int i = 0; i < comprimento; i++){
                printf("[%c]", display[i]);
            }
            printf("\nDigite uma letra: ");
            scanf(" %c", &letra);
            letra = toupper(letra);
            for(int i = 0; i < comprimento; i++){
                if(letra == palavra[i]){
                    display[i] = letra;
                    achou = 1;
                }
                if(display[i] == '?'){
                    vitoria = 0;
                }
            }
            system("cls");
            if(achou == 0){
                printf("Voce errou...\nMenos uma vida\n");
                vidas--;
            }
            if(vidas == 0 || vitoria == 1){
                if(vidas == 0){
                    printf("Voce perdeu...");
                    break;
                }
                if(vitoria == 1){
                    printf("Voce venceu...");
                    break;
                }
            }
        }
        printf("\nDeseja parar? [S/N]: ");
        scanf(" %c", &decisao);
        decisao = tolower(decisao);
        system("cls");
    } while(decisao != 's');

    return 0;
}
