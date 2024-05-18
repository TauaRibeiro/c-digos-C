#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void leitura(float *n1, float *n2);
float media(float *n1, float *n2, int tipo);

int main(){
    system("cls");
    setlocale(LC_ALL, "");

    float num1, num2;

    leitura(&num1, &num2);

    system("cls");

    printf("A média simples será: %.2f\n", media(&num1, &num2, 1));
    printf("A média ponderada será: %.2f", media(&num1, &num2, 2));

    return 0;
}

void leitura(float *n1, float *n2){
    
    printf("Digite o primeiro número: ");
    scanf("%f", &*n1);

    printf("Digite o segundo número: ");
    scanf("%f", &*n2);
}

float media(float *n1, float *n2, int tipo){
    float resultado;

    switch(tipo){
        
        case 1:
            resultado = (*n1 + *n2)/2;
        break;
        case 2:
            resultado = (*n1 + *n2 * 2)/3;
        break;
    }

    return resultado;

}
