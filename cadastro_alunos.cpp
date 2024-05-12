#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#define num_alunos 5
struct registro{
    char nome[num_alunos][100], situacao[num_alunos][50];
    int matricula[num_alunos];
    float medias[num_alunos], notas[num_alunos][3];
};

int main(){
    system("cls");
    setlocale(LC_ALL, "Portuguese");

    struct registro aluno;
    int maior_media, menor_media, maior_nota;

    for(int i = 0; i < num_alunos; i++){
        printf("Digite o nome do %d° aluno: ", i+1);
        scanf(" %100[^\n]s", aluno.nome[i]);
        printf("Digite o número da matrícula do %d° aluno: ", i+1);
        scanf("%d", &aluno.matricula[i]);

        for(int x = 0; x < 3; x++){
            system("cls");
            printf("Digite a nota da %d° prova: ", x+1);
            scanf("%f", &aluno.notas[i][x]);
            aluno.medias[i] += aluno.notas[i][x]; 
        }

        aluno.medias[i] /= 3;
        strcpy(aluno.situacao[i], (aluno.medias[i] >= 7) ? "APROVADO" : "REPORVADO");
        system("cls");
    }

    for(int i = 0; i < num_alunos; i++){
        if(i == 0){
            maior_media = 0;
            maior_nota = 0;
            menor_media = 0;
        }
        else{
            if(aluno.medias[maior_media] < aluno.medias[i]){
                maior_media = i;
            }
            if(aluno.medias[menor_media] > aluno.medias[i]){
                menor_media = i;
            }
            if(aluno.notas[maior_nota][0] < aluno.notas[i][0]){
                maior_nota = i;
            }
        }
    }

    for(int i = 0; i < num_alunos; i++){
        printf("NOME: %s\nMATRÍCULA: %d\nMÉDIA: %.2f\nSITUACAO: %s\n", aluno.nome[i], aluno.matricula,
        aluno.medias[i], aluno.situacao[i]);
        printf("-----------------------------------------\n");
    }
    printf("O aluno com a maior nota da primeira prova é: %s\n", aluno.nome[maior_nota]);
    printf("O aluno com a maior média é: %s\n", aluno.nome[maior_media]);
    printf("O aluno com a menor média é: %s\n", aluno.nome[menor_media]);

    return 0;
}
