#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int SomaDobro(int *a, int *b);

int main(){
    system("cls");
    setlocale(LC_ALL, "");

    int A, B;

    printf("Digite um número: ");
    scanf("%d", &A);

    printf("Digite outro número: ");
    scanf("%d", &B);

    printf("A soma do dobro desse números será: %d", SomaDobro(&A, &B));

    return 0;
}

int SomaDobro(int *a, int *b){
    int resultado;

    resultado = (*a * 2) + (*b * 2);

    return resultado;
}
