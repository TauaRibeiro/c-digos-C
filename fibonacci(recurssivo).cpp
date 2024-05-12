#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

void fibo(int elementos);

int main() {
    system("cls");
    setlocale(LC_ALL, "Portuguese");

    int elementos;
    printf("Digite quantos números apareçam: ");
    scanf("%d", &elementos);
    fibo(elementos);
    return 0;
}

int conta = 0, anterior = 0, atual = 0, temp;
void fibo(int elementos)
{
    if(conta <= elementos){
        if(conta == 0){
            printf("%d... ", atual);
            ++atual;
        }
        else if(conta == 1){
            printf("%d... ", atual);
        }
        else{
            printf("%d... ", anterior + atual);
            temp = anterior;
            anterior = atual;
            atual = atual + temp;
        }
        ++conta;
        fibo(elementos);
    }
}
