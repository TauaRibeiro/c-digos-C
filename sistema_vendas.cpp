#include <stdio.h>
#include <stdlib.h>

int main(){
    int vetor[30], total_semanas[7];
    char semanas[][100] = {"Domingo", "Segunda", "Terca", "Quarta", "Quinta", "Sexta", "Sabado"};

    for(int i = 0; i < 30; i++){
        printf("Digite o numero de vendas no %d° dia: ", i+1);
        scanf("%d", &vetor[i]);
        system("cls");
        if(i > 6){
            total_semanas[i % 7] += vetor[i];
        }
        else{
            total_semanas[i % 7] = vetor[i];
        }
    }

    for(int i = 0; i < 7; i++)
    {
        printf("%s -> %d;\n", semanas[i], total_semanas[i]);
    }
    return 0;
}
