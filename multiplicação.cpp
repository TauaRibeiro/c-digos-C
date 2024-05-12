#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

float Multip_Rec(float n1, float n2);

int main(){
    system("cls");
    setlocale(LC_ALL, "Portuguese");

    float num, multi;

    printf("Digite o número que deseja multiplicar: ");
    scanf("%f", &num);
    printf("Agora digite por quanto ele será multiplicado: ");
    scanf("%f", &multi);
    printf("O resultado será: %.2f", Multip_Rec(num, multi));
    return 0;
}

int cont = 0;
float memo = 0;

float Multip_Rec(float n1, float n2){
    if(cont < n2){
        memo = memo + n1;
        ++cont;
        Multip_Rec(n1, n2);
        return memo;
    }
    else{
        return memo;
    }
}
