#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

int veri_maior(int vetor[], int tamanho);

int main(){
    system("cls");
    setlocale(LC_ALL, "Portuguese");

    int vetor[5];
    for(int i = 0; i < 5; i++){
        printf("Digite %d° número: ", i+1);
        scanf("%d", &vetor[i]);
        system("cls");
    }
    printf("O maior número é %d", veri_maior(vetor, 4));
    return 0;
}

int cont = 5, maior_num;
int veri_maior(int vetor[], int tamanho){
    if(tamanho == 0){
        return vetor[0];
    }
    else{
        return((veri_maior(vetor, tamanho-1) > vetor[tamanho]) ? veri_maior(vetor, tamanho-1) : vetor[tamanho]);
    }
}
