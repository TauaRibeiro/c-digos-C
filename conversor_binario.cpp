#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int binario(int num);

int main(){
    system("cls");
    setlocale(LC_ALL, "Portuguese");

    int num;

    printf("Digite um número para converter para binário: ");
    scanf("%d", &num);

    system("cls");

    printf("O número %d em binário é %d", num, binario(num));
    
    return 1;
}

int binario(int num){
    int bi;
    
    if(num < 2){
        return num;
    }
    else{
        bi = (binario(num/2) * 10)+(num%2);

        return bi;
    }
}
