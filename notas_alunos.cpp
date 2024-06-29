#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

struct aluno{
    char nome[30];
    int numero;

    struct nota *boletim;
    struct aluno *proximo;
};

typedef aluno aluno;

struct nota{
    float nota_aluno[3];

    struct aluno *dono;
    struct nota *proximo;
};

typedef nota nota;

struct pilha{
    aluno *topo;
};

typedef pilha pilha;

struct fila{
    nota *inicio;
    nota *fim;
};

typedef fila fila;

int total_alunos = 0;

pilha *criarPilha(){
    pilha *nova = (pilha *)malloc(sizeof(pilha));

    nova->topo = NULL;

    return nova;
}

fila *criarFila(){
    fila *nova = (fila *)malloc(sizeof(fila));

    nova->inicio = NULL;
    nova->fim = NULL;

    return nova;
}

void cadastrarAluno(pilha *pi){
    aluno *novo = (aluno *)malloc(sizeof(aluno));

    printf("Digite o nome do aluno a ser cadastrado: ");
    scanf(" %29[^\n]s", novo->nome);

    novo->boletim = NULL;

    novo->numero = ++total_alunos;

    novo->proximo = pi->topo;

    pi->topo = novo;
}

void cadastrarNota(fila *fi, pilha *pi){
    if(pi->topo == NULL){
        printf("Não há alunos cadastrados...\n");

        return;
    }

    aluno *aux = pi->topo; 

    int numero;

    printf("Digite o número do aluno: ");
    scanf("%d", &numero);

    do{
        if(fi->inicio !=  NULL){
            nota *compara = fi->inicio;

            do{
                if(compara->dono->numero == numero){
                    printf("O aluno já tem nota cadastrada...\n");

                    return;
                }

                compara = compara->proximo;
            }while(compara != NULL);
        }

        if(aux->numero == numero){
            nota *nova = (nota *)malloc(sizeof(nota));

            nova->dono = aux;
            nova->proximo = NULL;

            for(int i = 0; i < 3; i++){
                do{
                    printf("Digite a %dº nota desse aluno: ", i+1);
                    scanf("%f", &nova->nota_aluno[i]);

                    if(nova->nota_aluno[i] >= 0 && nova->nota_aluno[i] <= 10){
                        break;
                    }

                    system("cls");

                    printf("Nota inválida, tente novamente...\n");
                }while(1);
            }

            aux->boletim = nova;

            if(fi->inicio == NULL){
                fi->inicio = nova;
                fi->fim = nova;
            }
            else{
                fi->fim->proximo = nova;
                fi->fim = nova;
            }

            printf("Notas cadastradas com sucesso!!\n");

            return;
        }

        aux = aux->proximo;
    }while(aux != NULL);

    printf("Aluno não encontrado\n");
}

float mediaAluno(fila *fi){
    if(fi->inicio == NULL){
        printf("Não há notas cadastradas...\n");
        
        return -1;
    }

    nota *aux = fi->inicio;

    float media = 0;
    int num;

    printf("Digite o número do aluno: ");
    scanf("%d", &num);

    aux = fi->inicio;

    do{
        if(aux->dono->numero == num){
            for(int i = 0; i < 3; i++){
                media += aux->nota_aluno[i];
            }

            media /= 3;

            return media;
        }

        aux = aux->proximo;
    }while(aux != NULL);

    return -1;
}

void excluirNota(fila *fi){
    if(fi->inicio == NULL){
        printf("Não há notas cadastradas...\n");

        return;
    }

    nota *aux = fi->inicio;

    aux->dono->boletim = NULL;

    fi->inicio = fi->inicio->proximo;

    printf("Nota removida com sucesso!!\n");

    free(aux);
}

void excluirAluno(pilha *pi){
    if(pi->topo == NULL){
        printf("Não há alunos cadastrados...\n");

        return;
    }

    aluno *aux = pi->topo;

    pi->topo = pi->topo->proximo;

    free(aux);

    printf("Aluno removido com sucesso...\n");
}

void mostrarAlunos(pilha *pi){
    if(pi->topo == NULL){
        printf("Não há alunos cadastrados...\n");

        return;
    }

    aluno *aux = pi->topo;

    int achou = 0;

    do{
        if(aux->boletim == NULL){
            printf("NÚMERO-%d\nNOME-%s\n\n", aux->numero, aux->nome);

            achou = 1;
        }

        aux = aux->proximo;
    }while(aux != NULL);

    if(achou == 0){
        printf("Não há alunos sem nota\n");
    }
}

int main(){
    setlocale(LC_ALL, "Portuguese");

    fila *fila = criarFila();
    pilha *pilha = criarPilha();

    int escolha;
    float media;

    do{
        printf("1. Cadastrar aluno\n2. Cadastrar notas\n3. Calcular media\n");
        printf("4. Listar os nomes dos alunos sem nota\n5. Excluir nota\n6. Excluir aluno\n");
        printf("7. Sair\n");
        printf("Digite o número da opção desejada: ");
        scanf("%d", &escolha);

        system("cls");

        switch(escolha){
            case 1:
                cadastrarAluno(pilha);
            break;
            case 2:
                cadastrarNota(fila, pilha);
            break;
            case 3:
                media = mediaAluno(fila);

                if(media  > -1){
                    printf("A media será %.2f\n", media);
                }
            break;
            case 4:
                mostrarAlunos(pilha);
            break;
            case 5:
                excluirNota(fila);
            break;
            case 6:
                excluirAluno(pilha);
            break;
            case 7:
            break;
            default:
                printf("Opção inválida, tente novamente...\n");
            break;
        }
    }while(escolha != 7);
    return 1;
}
