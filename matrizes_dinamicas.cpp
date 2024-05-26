#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void ProcuraMaiores(int vetor[3], int **matriz, int linha, int coluna);

int main(){
    system("cls");
    setlocale(LC_ALL, "Portuguese");

    int **matriz;
    int maiores[3], linhas, colunas;

    printf("Digite o número de linhas da matriz: ");
    scanf("%d", &linhas);

    printf("Digite o número de colunas da matriz: ");
    scanf("%d", &colunas);

    matriz = (int **)malloc(linhas*sizeof(int));

    for(int i = 0; i < colunas; i++){
        matriz[i] = (int *)malloc(colunas*sizeof(int));
    }

    for(int i = 0; i < linhas; i++){
        for(int x = 0; x < colunas; x++){
            printf("Digite o número para a %d° linha e %d° coluna: ", i+1, x+1);
            scanf("%d", &matriz[i][x]);
        }

        system("cls");
    }

    ProcuraMaiores(maiores, matriz, linhas, colunas);

    printf("ok\n");
    printf("Matriz original:\n");
    for(int i = 0; i < linhas; i++){
        for(int x = 0; x < colunas; x++){
            printf("%d ", matriz[i][x]);
        }
        printf("%c", '\n');
    }
    printf("ok\n");

    printf("Matriz transposta:\n");
    for(int i = 0; i < colunas; i++){
        for(int x = 0; x < linhas; x++){
            printf("%d ", matriz[x][i]);
        }
        printf("%c", '\n');
    }

    printf("Os maiores número na matriz são: %d, %d e %d", maiores[0], maiores[1], maiores[2]);

    for(int i = 0; i < linhas; i++){
        free(matriz[i])
    }
    free(matriz)
    return 0;
}

void ProcuraMaiores(int vetor[3], int **matriz, int linha, int coluna){
    int preenchidos = 0;
    for(int i = 0; i < linha; i++){
        for(int x = 0; x < coluna; x++){
            if(preenchidos <= 2){
                vetor[preenchidos] = matriz[i][x];
            }
            else{
                for(int z = 0; z < 3; z++){
                    if(matriz[i][x] > vetor[z]){
                        vetor[z] = matriz[i][x];
                        break;
                    }
                }
            }
        }
    }
}
