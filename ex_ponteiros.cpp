#include <stdio.h>
#include <stdlib.h>

int main(){
    int num1 = 1, *num1_ptr;
    float num2 = 2.5, *num2_ptr;
    char letra = 'c', *letra_ptr;

    num1_ptr = &num1;
    num2_ptr = &num2;
    letra_ptr = &letra;

    printf("VALORES INICIAIS:\n");
    printf("%d;\n%f;\n%c;\n", num1, num2, letra);

    *num1_ptr = 8;
    *num2_ptr = 4.5;
    *letra_ptr = 'b';

    printf("\nVALORES NOVOS:\n");
    printf("%d;\n%f;\n%c;", num1, num2, letra);


    return 0;
}
