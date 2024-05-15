#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <locale.h>

#define num_pessoas 5

struct dados {
    char nome[num_pessoas][100];
    char endereco[num_pessoas][100];
    long int telefone[num_pessoas];
};

struct dados ordem_alfa(struct dados d);
void linha(void);

int main() {
    setlocale(LC_ALL, "Portuguese");

    struct dados pessoa;

    for (int i = 0; i < num_pessoas; i++) {
        printf("Digite o nome da %d° pessoa: ", i + 1);
        scanf(" %99[^\n]", pessoa.nome[i]);
        printf("Digite o endereço da %d° pessoa: ", i + 1);
        scanf(" %99[^\n]", pessoa.endereco[i]);
        printf("Digite apenas os números do número de telefone da %d° pessoa: ", i + 1);
        scanf("%ld", &pessoa.telefone[i]);
        system("cls");
    }

    pessoa = ordem_alfa(pessoa);

    for (int i = 0; i < num_pessoas; i++) {
        linha();
        printf("NOME: %s\nENDEREÇO: %s\nTELEFONE: %ld\n", pessoa.nome[i], pessoa.endereco[i], pessoa.telefone[i]);
        linha();
    }

    return 0;
}

struct dados ordem_alfa(struct dados d) {
    char temp_nome[100], temp_endereco[100];
    long int temp_telefone;

    for (int i = 0; i < num_pessoas - 1; i++) {
        for (int j = i + 1; j < num_pessoas; j++) {
            if (strcmp(d.nome[i], d.nome[j]) > 0) {
                strcpy(temp_nome, d.nome[i]);
                strcpy(d.nome[i], d.nome[j]);
                strcpy(d.nome[j], temp_nome);

                strcpy(temp_endereco, d.endereco[i]);
                strcpy(d.endereco[i], d.endereco[j]);
                strcpy(d.endereco[j], temp_endereco);
                
                temp_telefone = d.telefone[i];
                d.telefone[i] = d.telefone[j];
                d.telefone[j] = temp_telefone;
            }
        }
    }

    return d;
}

void linha(void) {
    printf("======================================================\n");
}
