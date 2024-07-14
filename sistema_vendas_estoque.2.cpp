/*Inspiração
Um sistema de vendas e estoque no qual participei na construção;
Onde pode ser tanto encontrado no meu github ou em
https://github.com/MarcosCondeJr/Sistema-de-Vendas-e-Estoque */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <locale.h>
#include <string.h>
/*IDEIA
Criar um novo sistema de vendas e estoque melhorado usando os conhecimentos aprendidos, deve possibilitar:
1- Funções CRUD de produtos e clientes
2- Aplicar descontos com base na localidade do cliente e tipo do produto
3- Gravar os dados (atualizados) em um arquivo para que seja possível armazenar as informações
*/


//Constante para o máximo de caracteres
#define MAX_CARACTERES 30

//Estrutura para armazenar os dados dos clientes
struct cliente{
    char nome[MAX_CARACTERES];
    char localidade[3];
    char cpf[12];
    int idade;

    struct cliente *esquerda;
    struct cliente *direita;
};
//Estrutura para armazenar os dados dos produtos
struct produto{
    char nome[MAX_CARACTERES];
    char tipo[MAX_CARACTERES];
    float preco;
    int quantidade;
    int identificacao;

    struct produto *proximo;
    struct produto *anterior;
};
//Estrutura que armazena os dados dos pedidos do cliente
struct pedido{
    struct produto produto_pedido;

    struct pedido *proximo;
    struct pedido *anterior;
};
//Árvore que armazena os dados dos clientes
struct arvore_cliente{
    struct cliente *raiz;
};
//Árvore que armazena os dados dos produtos
struct lista_produtos{
    struct produto *inicio;
    struct produto *fim;
};
//Lista que armazena o início e fim da lista de compras de um usuário
struct carrinho{
    char nome[MAX_CARACTERES];

    struct pedido *inicio;
    struct pedido *fim;
};

typedef struct cliente cliente;
typedef struct produto produto;
typedef struct pedido pedido;
typedef struct arvore_cliente arv_cliente;
typedef struct lista_produtos lis_produtos;
typedef struct carrinho carrinho;

int id_produto = 1;

//Função responsável por imprimir um tipo de linha com um determinado comprimento
void ImprimirLinha(const char *tipo, int comprimento){
    int i;

    printf("\n");
    for(i = 0; i < comprimento; i++){
        printf(tipo);
    }
    printf("\n");
}

/*Função responsável por imprimir uma string formatada com um determinado separador e determinado tamanho:
TIPO FORMATAÇÃO-
'<' - Alinhado à esquerda
'>' - Alinhado à direita
'^'(usado por conveniência) - Centralizado*/
void Formatar(const char *string, int tamanho, char separador, char alinhamento){
    int qtd_caracter = 0, compr_string = strlen(string), i;

    if(alinhamento == '<'){
        for(i = 0; i < tamanho; i++){
            if(qtd_caracter < compr_string){
                printf("%c", string[i]);

                qtd_caracter++;
            }
            else{
                printf("%c", separador);
            }
        }
    }
    else if(alinhamento == '>'){
        for(i = 0; i < tamanho; i++){
            if(tamanho - qtd_caracter <= compr_string){
                printf("%c", string[tamanho-qtd_caracter-1]);
            }
            else{
                printf("%c", separador);

                qtd_caracter++;
            }
        }
    }
    else{
        int centro = 0;

        for(i = 0; i < tamanho; i++){
            if((i < tamanho/2 && !centro) || (!(i < tamanho/2) && centro)){
                printf("%c", separador);
            }
            else{
                if(qtd_caracter < compr_string){
                    printf("%c", string[qtd_caracter++]);
                }
                else{
                    centro = 1;
                }
            }
        }
    }
}

//Função responsável por criar a árvore de dados dos clientes
arv_cliente *CriarArvoreCliente(){
    arv_cliente *novo = (arv_cliente *)malloc(sizeof(arv_cliente));

    novo->raiz = NULL;

    return novo;
}

//Função responsável por criar a árvore de dados dos produtos
lis_produtos *CriarListaProdutos(){
    lis_produtos *novo = (lis_produtos *)malloc(sizeof(lis_produtos));

    novo->inicio = NULL;
    novo->fim = NULL;

    return novo;
}

//Função responsável por cadastrar os clientes
void CadastrarCliente(arv_cliente *arv){
    int achou = 0;

    cliente *novo = (cliente *)malloc(sizeof(cliente));

    printf("Digite o nome do cliente: ");
    scanf(" %29[^\n]s", novo->nome);

    printf("Digite a idade de %s: ", novo->nome);
    scanf("%d", &novo->idade);

    printf("Digite o CPF de %s: ", novo->nome);
    scanf(" %11[^\n]s", novo->cpf);

    printf("Digite a sigla do estado desse cliete: ");
    scanf(" %2[^\n]s", novo->localidade);

    novo->direita = NULL;
    novo->esquerda = NULL;
    
    system("cls");

    if(arv->raiz == NULL){
        arv->raiz = novo;
    }
    else{
        cliente *aux = arv->raiz;
        int cpf_aux, novo_cpf;

        while(!achou){
            sscanf(novo->cpf, "%d", &novo_cpf);
            sscanf(novo->cpf, "%d", &cpf_aux);

            if(novo->cpf > aux->cpf){
                if(aux->esquerda == NULL){
                    aux->esquerda = novo;

                    achou = 1;
                }
                else{
                    aux = aux->esquerda;
                }
            }
            else{
                if(aux->direita == NULL){
                    aux->direita = novo;

                    achou = 1;
                }
                else{
                    aux = aux->direita;
                }
            }
        }
    }

    printf("Cliente cadastrado com sucesso!!");    
}

//Função responsável por cadastrar os produtos
void CadastrarProdutos(lis_produtos *lis){
    produto *novo = (produto *)malloc(sizeof(produto));

    printf("Digite o nome do produto: ");
    scanf(" %29[^\n]s", novo->nome);

    printf("Digite a quantidade de %s: ", novo->nome);
    scanf("%d", &novo->quantidade);

    printf("Digite o tipo de %s (ex: limpeza, alimentício): ", novo->nome);
    scanf(" %29[^\n]s", novo->tipo);

    printf("Digite o preço de %s: R$ ", novo->nome);
    scanf("%f", &novo->preco);

    novo->identificacao = id_produto++;

    if(lis->inicio == NULL){
        novo->proximo = NULL;
        novo->anterior = NULL;

        lis->inicio = novo;
        lis->fim = novo;
    }
    else{
        novo->proximo = NULL;
        novo->anterior = lis->fim;

        lis->fim->proximo = novo;
        lis->fim = novo;
    }

    printf("Produto cadastrado com sucesso!!\n");
}

//Função responsável por mostrar todos os produtos
void MostrarProdutos(lis_produtos *lis){
    if(lis->inicio == NULL){
        printf("Não há produtos cadastrados...\n");

        return;
    }

    produto *aux = lis->inicio;

    do{
        ImprimirLinha("-", 50);
        printf("NOME: %s\n", aux->nome);
        printf("ID: %d\n", aux->identificacao);
        printf("TIPO: %s\n", aux->tipo);
        printf("QUANTIDADE: %d\n", aux->quantidade);
        printf("PREÇO: %.2f\n", aux->preco);
        ImprimirLinha("-", 50);

        aux = aux->proximo;
    }while(aux != NULL);
}

//Função responsável por mostrar todos os clientes cadastrados
void MostrarClientes(arv_cliente *arv, cliente *no){
    if(arv->raiz == NULL){
        printf("Não há clientes cadastrados...\n");

        return;
    }

    if(no == NULL){
        return;
    }

    ImprimirLinha("-", 50);
    printf("NOME: %s\n", no->nome);
    printf("IDADE: %d\n", no->idade);
    printf("LOCALIDADE: %s\n", no->localidade);
    printf("CPF: %s\n", no->cpf);
    ImprimirLinha("-", 50);

    MostrarClientes(arv, no->esquerda);

    MostrarClientes(arv, no->direita);
}

//Função responsável por atualizar um produto cadastrado
void AtualizarProduto(lis_produtos *lis){
    if(lis->inicio == NULL){
        printf("Não há produtos cadastrado...\n");

        return;
    }

    int id;

    printf("Digite o id do produto que deseja atualizar: ");
    scanf("%d", &id);

    if(id > id_produto){
        printf("Produto não encontrado...\n");
    }

    
}

//Fução responsável por atualizar um cliente cadastrado
void AtualizarCliente(arv_cliente *arv){
    if(arv->raiz == NULL){
        printf("Não há clientes cadastrados...\n");

        return;
    }

    int cpf, cpf_aux ,decisao;
    int achou = 0;

    printf("Digite o número do cpf da pessoa que deseja atualizar: ");
    scanf("%d", &cpf);

    cliente *aux = arv->raiz;

    while(aux != NULL && achou == 0){
        sscanf(aux->cpf, "%d", &cpf_aux);

        if(cpf_aux == cpf){
            achou++;
        }
        else if(cpf > cpf_aux){
            aux = aux->esquerda;
        }
        else{
            aux = aux->direita;
        }
    }

    if(achou == 0){
        printf("Cliente não encontrado...\n");

        return;
    }

    ImprimirLinha("=", 50);
    printf("Cliente encontrado!! Qual informação deseja atualizar?");
    
    do{
        ImprimirLinha("=", 50);
        printf("1. Idade\n");
        printf("2. Localicalidade\n");
        ImprimirLinha("-", 50);
        printf("Digite o número da opção desejada: ");
        scanf("%d", &decisao);
        
        system("cls");
        switch(decisao){
            case 1:
                printf("Digite a nova idade: ");
                scanf("%d", &aux->idade);
            break;
            case 2:
                printf("Digite a nova localidade: ");
                scanf(" %2[^\n]s", aux->localidade);
            break;
            default:
                printf("Escolha inválida...\n");
            break;
        }
    }while(decisao != 1 && decisao != 2);

    printf("Atualizado com sucesso!!\n");
}

//Função responsável por deletar um cliente cadastrado
void DeletarCliente(arv_cliente *arv){
    if(arv->raiz == NULL){
        printf("Não há clientes cadastrados...\n");

        return;
    }

    int cpf, cpf_aux;
    int achou = 0;

    printf("Digite a identificação do cliente a ser deletado: ");
    scanf("%d", &cpf);

    cliente *atual = arv->raiz;
    cliente *pai;

    while(atual != NULL && achou == 0){
        sscanf(atual->cpf, "%d", &cpf_aux);

        if(cpf == cpf_aux){
            achou++;
        }
        else if(cpf_aux > cpf){
            pai = atual;

            atual = atual->esquerda;
        }
        else{
            pai = atual;

            atual = atual->direita;
        }
    }

    if(atual->direita == NULL && atual->esquerda == NULL){
        if(atual == arv->raiz){
            arv->raiz = NULL;
        }

        if(pai->direita == atual){
            pai->direita = NULL;
        }
        else{
            pai->esquerda = NULL;
        }

        free(atual);
    }
    else if(atual->direita == NULL || atual->esquerda == NULL){
        cliente *filho;

        if(atual->direita != NULL){
            filho = atual->direita;
        }
        else{
            filho = atual->esquerda;
        }

        if(atual == arv->raiz){
            arv->raiz = filho;
        }
        else if(pai->esquerda == atual){
            pai->esquerda = filho;
        }
        else{
            pai->direita = filho;
        }

        free(atual);
    }
    else{
        cliente *sucessor = atual->direita;
        cliente *pai_sucessor;

        while(sucessor->esquerda != NULL){
            pai_sucessor = sucessor;

            sucessor = sucessor->esquerda;
        }

        strcpy(atual->nome, sucessor->nome);
        strcpy(atual->localidade, sucessor->localidade);
        atual->idade = sucessor->idade;
        strcpy(atual->cpf, sucessor->cpf);

        if(pai_sucessor->direita == sucessor){
            pai_sucessor->direita = sucessor->direita;
        }
        else{
            pai_sucessor->esquerda = sucessor->direita;
        }

        free(sucessor);
    }

    printf("Cliente deletado com sucesso!!\n");
}

/*Função responsável por efetuar o login
retorna 1 caso o login ocorreu com sucesso
caso contrário, retorna 0*/
int login(){
    int senha, codigo_usuario;

    printf("Digite o código de ususário: ");
    scanf("%d", &codigo_usuario);

    printf("Digite a senha: ");
    scanf("%d", &senha);

    system("cls");

    if(codigo_usuario == 4382 && senha == 1234){
        printf("Login efetuado com sucesso!!\n");

        return 1;
    }

    printf("Senha ou código de usuário incorretos...\n");

    return 0;
}

/*Função principal onde vai conter a IU e o chamado das funções
CODIGO USUÁRIO - 4382
SENHA - 1234*/
int main(){
    setlocale(LC_ALL, "portuguese");

    arv_cliente *clientes = CriarArvoreCliente();
    lis_produtos *produtos = CriarListaProdutos();

    int decisao = 1;
    do{
        if(login()){
            do{
                ImprimirLinha("=", 50);
                printf("Digite o módulo de sistema que deseja acessar");
                ImprimirLinha("-", 50);
                printf("1. Vendas\n");
                printf("2. Estoque\n");
                printf("3. Sair do sistema\n");
                ImprimirLinha("-", 50);
                printf("Digite o número da opção desejada: ");
                scanf("%d", &decisao);

                system("cls");
                switch(decisao){
                    case 1:
                        do{
                                
                            ImprimirLinha("=", 50);
                            Formatar("VENDAS", 40, ' ', '^');
                            ImprimirLinha("-", 50);
                            printf("1. Cadastrar cliente\n");
                            printf("2. Mostrar todos os clientes\n");
                            printf("3. Atualizar cliente\n");
                            printf("4. Deletar cliente\n");
                            printf("5. Aplicar desconto/imposto\n");
                            printf("6. Efetuar compra\n");
                            printf("7. Vizualizar carrinho\n");
                            printf("8. Voltar\n");
                            ImprimirLinha("-", 50);
                            printf("Digite o número da opção desejada: ");
                            scanf("%d", &decisao);
                            
                            system("cls");

                            switch(decisao){
                                case 1:
                                    CadastrarCliente(clientes);
                                break;
                                case 2:
                                    MostrarClientes(clientes, clientes->raiz);
                                break;
                                case 3:
                                    AtualizarCliente(clientes);
                                break;
                                case 4:
                                    DeletarCliente(clientes);
                                break;
                                case 8:
                                break;
                                default:
                                    printf("Escolha inválida, tente novamente...");
                                break;
                            }
                        }while(decisao != 8);
                    break;
                    case 2:
                        do{
                            ImprimirLinha("=", 50);
                            Formatar("ESTOQUE", 40, ' ', '^');
                            ImprimirLinha("-", 50);
                            printf("1. Cadastrar produto\n");
                            printf("2. Atualizar produto\n");
                            printf("3. Deletar produto\n");
                            printf("4. Mostrar todos os produtos\n");
                            printf("5. Voltar\n");
                            ImprimirLinha("-", 50);
                            printf("Digite o número da opção desejada: ");
                            scanf("%d", &decisao);
                            
                            system("cls");

                            switch(decisao){
                                case 1:
                                    CadastrarProdutos(produtos);
                                break;
                                case 2:
                                break;
                                case 4:
                                    MostrarProdutos(produtos);
                                break;
                                case 5:
                                break;
                                default:
                                    printf("Escolha inválida, tente novamente...\n");
                                break;
                            }
                        }while(decisao != 5);
                    break;
                }
            }while(decisao != 3);
        }
    }while(decisao != 3);
    return 1;
}
