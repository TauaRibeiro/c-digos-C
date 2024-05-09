#include <stdio.h>
int main(){
	int escolha;
	printf("Escolha o preriodo do tempo em que esta:\n");
	printf("1- 21 de marco - 21 junho;\n2 - 21 de junho - 23 setembro;\n3- 23 de setembro - 21 de dezembro;\n4- 21 de dezembro - 21 de marco;\n");
	printf("Digite o numero da opcao escolhida: ");
	scanf("%d", &escolha);
	switch(escolha){
		case 1 : printf("Outono"); break;
		case 2 : printf("Inverno"); break;
		case 3 : printf("Primavera"); break;
		case 4 : printf("Verao"); break;
	}
	return 0;
}