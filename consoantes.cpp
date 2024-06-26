#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <ctype.h>

void aloca(int tamanho, char *ptr);


int main(){
    system("cls");
    setlocale(LC_ALL, "portuguese");

    char *ptr = (char *)malloc(sizeof(char));
    char vogais[] = "aeiou";
    int tamanho, vogal;

    printf("Digite o tamanho da string: ");
    scanf("%d", &tamanho);

    aloca(tamanho, ptr);

    printf("Digite a string: ");
    scanf(" %[^\n]", ptr);

    printf("String sem vogais: ");
    for(int i = 0; ptr[i] != '\0'; i++){
        vogal = 0;

        for(int x = 0; x < 28; x++){
            if(tolower(ptr[i]) == vogais[x]){
                vogal = 1;
            }
        }

        if(!(vogal)){
            printf("%c", ptr[i]);
        }
    }

    free(*ptr);
    return 0;
}

void aloca(int tamanho, char *ptr){
    ptr = (char *)realloc(ptr, tamanho*sizeof(char));
}
