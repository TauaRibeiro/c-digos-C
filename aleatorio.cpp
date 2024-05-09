#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(){
	srand(time(NULL));
	int aletorio = rand()%101, adivinhacao;
	printf("%d\n", aletorio);
	while(adivinhacao != aletorio){
		printf("Digite um numero entre 1 e 100: ");
		scanf("%d", &adivinhacao);
		system("cls");
	}
}