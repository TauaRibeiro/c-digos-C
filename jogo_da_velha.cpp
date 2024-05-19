#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <ctype.h>
//Prototipagem da função vitória;
int vitoria(int posicao, char jogo[9]);

int main(){
    system("cls");
    setlocale(LC_ALL, "Portuguese");
    //Declaração das variáveis;
    char jogo[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}, vez = 'X';
    int vitoria = 0, livre = 9, escolha;
    //Loop que irá rodar o jogo enquanto houver espaços lives e niguem ter vencido;
    do{
        do{
            printf("%s", (vez == 'X') ? "Vez do X\n" : "Vez da O\n");

            for(int i = 0; i < 9; i++){
                if(jogo[i] == ' '){
                    printf("[%d]", i+1 );
                }
                else{
                    printf("[%c]", jogo[i]);
                }

                if(i == 2 || i == 5 || i == 8){
                    printf("%c", '\n');
                }
            }

            printf("Digite o número em que gostaria de de jogar: ");
            scanf("%d", &escolha);

            system("cls");

            if(escolha >= 1 && escolha <= 9 && jogo[escolha-1] == ' '){
                jogo[escolha-1] = toupper(vez);
                break;
            }

        }while(1);
        
        livre--;

        vitoria = jogada(escolha, jogo);

        (vez == 'X') ? vez = 'O' : vez = 'X';

    }while(vitoria == 0 && livre > 0);
    //Saída do resultado do jogo;
    if(vitoria == 0){
        printf("EMPATE");
    }
    else{
        printf("O jogador %s venceu!!", (vez == 'O') ? "do X" : "da O");
    }
    
    return 0;
}
//Função resposável por verificar se alguém venceu o jogo;
int vitoria(int posicao, char jogo[9]){
    int linha;
    if(posicao <= 3){
        posicao -= 1;
        linha = 0;
    }
    else if(posicao <= 6){
        posicao -= 5;
        linha = 3;
    }
    else{
        posicao -= 7;
        linha = 6;
    }
    
    if(jogo[linha] == jogo[linha+1] && jogo[linha+1] == jogo[linha+2]
    && jogo[linha] == jogo[linha+2] && jogo[linha] != ' '){
        return 1;
    }
    else if(jogo[posicao] == jogo[posicao+3] && jogo[posicao+3] == jogo[posicao+6] 
    && jogo[posicao+6] == jogo[posicao+3] && jogo[posicao] != ' '){
        return 1;
    }
    else if(jogo[0] == jogo[4] && jogo[0] == jogo[8] && jogo[4] == jogo[8] && jogo[0] != ' '){
        return 1;
    }
    else if(jogo[2] == jogo[4] && jogo[2] == jogo[6] && jogo[4] == jogo[6] && jogo[2] != ' '){
        return 1;
    }
    
    return 0;
}
