#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int ordem(int *v);

int main(){
    system("cls");
    setlocale(LC_ALL, "");

    int vetor[3];

    for(int i = 0; i < 3; i++){
        printf("Digite o %d° número: ", i+1);
        scanf("%d", &vetor[i]);
    }

    if(ordem(vetor) == 1){

        printf("TODOS OS VALORES SÃO IGUAIS");
    }
    else{

        for(int i = 0; i < 3; i++){
            printf("%d;\n", vetor[i]);
        }
    }

    return 0;
}

int ordem(int *v){
    int temp;

    if(*(v) == *(v + 1) && *(v) == *(v + 2) && *(v + 2) == *(v + 1)){
        
        return 1;

    }

    else{
        
        for(int i = 0; i < 3; i++){
        
            for(int x = 0; x < 2; x++){
        
                if(*(v + x) > *(v + x + 1)){
                    temp = *(v + x);
                    *(v + x) = *(v + x + 1);
                    *(v + x + 1) = temp;
                }
            }
        }

        return 0;
    }
}
