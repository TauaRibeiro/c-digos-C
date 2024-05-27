#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

struct cidade{
    char nome[30];
    int x, y;
};

int main(){
    system("cls");
    setlocale(LC_ALL, "Portuguese");
    
    struct cidade *cidade;
    int **matriz;
    int num_cidades, distancia, d_x, d_y, calculo;

    printf("Digite quantas cidades você gostaria de cadastrar: ");
    scanf("%d", &num_cidades);

    cidade = (struct cidade *)malloc(num_cidades*sizeof(struct cidade));
    
    matriz = (int **)malloc(num_cidades*sizeof(int *));
    for(int i = 0; i < num_cidades; i++){
        matriz[i] = (int *)malloc(num_cidades*sizeof(int));
    }

    for(int i = 0; i < num_cidades; i++){
        printf("Digite o nome da %d° cidade: ", i+1);
        scanf(" %29[^\n]", cidade[i].nome);

        printf("Digite a coordenada X dessa cidade: ");
        scanf("%d", &cidade[i].x);

        printf("Digite a coodenada Y dessa cidade: ");
        scanf("%d", &cidade[i].y);

        system("cls");
    }

    for(int i = 0; i < num_cidades; i++){
        calculo = 0;

        for(int z = 0; z < num_cidades; z++){
            if(i != z && !(calculo)){
                for(int c = 0; c < i; c++){
                    matriz[i][c] = matriz[c][i];
                } 
            }
            else if(i == z){
                matriz[i][z] = 0;

                calculo = 1;
            }
            else{
                d_x = cidade[i].x - cidade[z].x;
                d_x = (d_x < 0) ? -d_x : d_x;

                d_y = cidade[i].y - cidade[z].y;
                d_y = (d_y < 0) ? -d_y : d_y;

                distancia = d_x + d_y;
                
                matriz[i][z] = distancia;
            }
        }
    }
    printf("Colunas/linhas: ");
    for(int i = 0; i < num_cidades; i++){
        printf("%s%s", cidade[i].nome, (i < num_cidades-1) ? ", " : ";\n");
    }
    printf("A matriz de distancias será a seguinte:\n\n");

    for(int i = 0; i < num_cidades; i++){
        for(int z = 0; z < num_cidades; z++){
            printf("[%d]", matriz[i][z]);
        }
        printf("\n");
    }


    return 0;
}
