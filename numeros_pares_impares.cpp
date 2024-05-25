#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(){
    system("cls");
    setlocale(LC_ALL, "portuguese");

    int tamanho, pares = 0, impares = 0;

    printf("Digite quantos números serão digitados: ");
    scanf("%d", &tamanho);

    int *ptr = (int *)malloc(tamanho*sizeof(int));

    for(int i = 0; i < tamanho; i++){
        printf("Digite o %d° número: ", i+1);
        scanf("%d", &ptr[i]);

        if(ptr[i] % 2 == 0 ){
            pares++;
        }
        else{
            impares++;
        }
    }

    system("cls");

    printf("Os números digitados foram: ");
    for(int i = 0; i < tamanho; i++){
        printf("%d%s", ptr[i], (i < tamanho-1) ? ", " : ";\n");
    }
    printf("O vetor tinha %d %s;\n", pares, (pares > 1) ? "números pares" : "número par");
    printf("O vetor tinha %d %s;\n", impares, (impares > 1) ? "números ímpares" : "número ímpar");


    return 0;
}
