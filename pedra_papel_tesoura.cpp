#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(){
	srand(time(NULL));
	int decisao, bot;
	do{
		bot = (rand()%3)+1;
		do{
			printf("Faca a sua escolha: ");
			printf("\n1- Pedra;\n2- Papel;\n3- Tesoura;\n");
			printf("Digite o numero da sua escolha: ");
			scanf("%d", &decisao);
			system("cls");
		}while(decisao > 3 || decisao <= 0);
		if(decisao == 1 && bot == 3){
			printf("Voce venceu!!");
			break;
		}
		if(decisao == 2 && bot == 1){
			printf("Voce venceu!!");
			break;
		}
		if(decisao == 3 && bot == 2){
			printf("Voce venceu!!");
			break;
		}
		system("cls");
		printf("Voce perdeu... tente novamente\n");
	}while(1);
	return 0;
}