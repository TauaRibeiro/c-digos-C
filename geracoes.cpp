#include <stdio.h>
int main(){
	int escolha;
	printf("Digite a faixa de anos em que se encaixa: ");
	printf("\n1- 1965 - 1980;\n2- 1981 - 1996;\n3- 1997 - 2010;\n4- 2010++\n");
	printf("Digite o numero da sua escolha: ");
	scanf("%d", &escolha);
	printf("Gerecao ");
	switch(escolha){
		case 1 : printf("X"); break;
		case 2 : printf("Y"); break;
		case 3 : printf("Z"); break;
		case 4 : printf("Alpha"); break;
	}
	return 0;
}