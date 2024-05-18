#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(){
    system("cls");
    setlocale(LC_ALL, "");

    int vetor[5];
    int *ptr = vetor;

    for(int i = 0; i < 5; i++){
        printf("Digite o %d° número:\n", i+1);
        scanf("%d", &*(ptr + i));
    }

    system("cls");

    for(int i = 0; i < 5; i++){
        printf("%d\n", *(ptr + i) * 2);
    }
    return 0;
}
