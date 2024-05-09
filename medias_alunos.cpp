#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(){
    char nomes[20][100];
    float medias[20] = {0}, nota, media_turma = 0;
    for(int i = 0; i < 20; i++){
        printf("Digite o nome do aluno: ");
        scanf("%s", nomes[i]);
        for(int x = 0; x < 3; x++){
            printf("Digite a %d nota do aluno %s: ", x+1, nomes[i]);
            scanf("%f", &nota);
            medias[i] += nota;
            if(x == 2){
                medias[i] /= 3;
                media_turma += medias[i];
            }
            system("cls");
        }
    }
    for(int i = 0; i < 20; i++){
        printf("NOME: %s---- MEDIA: %.2f;\n", nomes[i], medias[i]);
    }
    printf("A media da turma sera: %.2f", media_turma/20);

    return 0;
}
