#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <ctype.h>

struct registro{
    char nome[30];
    int matricula, nascimento[3];
};

void cadastro(struct registro *aluno, int quantidade);

int main(){
    system("cls");
    setlocale(LC_ALL, "portuguese");

    struct registro *aluno;
    int qtd;

    printf("Digite a quantidade de alunos a serem cadastrados: ");
    scanf("%d", &qtd);

    aluno = (struct registro *)malloc(qtd * sizeof(struct registro));
    cadastro(aluno, qtd);

    for(int i = 0; i < qtd; i++){
        printf("NOME: %s;\nMATRÍCULA: %d;\n", aluno[i].nome, aluno[i].matricula);
        printf("DATA DE NASCIMENTO: %.2d/%.2d/%d;\n", aluno[i].nascimento[0], aluno[i].nascimento[1],
        aluno[i].nascimento[2]);

        printf("------------------------------------\n");
    }

    free(aluno);
    return 0;
}

void cadastro(struct registro *aluno, int quantidade){
    int valido, dia, mes, ano;

    for(int i = 0; i < quantidade; i++){
        printf("Digite o nome do %d° aluno: ", i+1);
        scanf(" %29[^\n]", aluno[i].nome);

        printf("Digite o número da matrícula: ");
        scanf("%d", &aluno[i].matricula);

        do{
            dia = mes = ano = 0;

            valido = 0;

            printf("Digite a data de nascimento (dd/mm/aaaa): ");
            scanf(" %d/%d/%d", &dia, &mes, &ano);

            if(dia != 0 && mes != 0 && ano != 0){
                aluno[i].nascimento[0] = dia;
                aluno[i].nascimento[1] = mes;
                aluno[i].nascimento[2] = ano;

                valido = 1;
            }

            system("cls");
        }while(!(valido));
    }
   
}
