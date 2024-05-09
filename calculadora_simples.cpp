#include <stdio.h>
#include <stdlib.h>
int main(){
	int num1, num2, escolha;
	printf("Digite um numero: ");
	scanf("%d", &num1);
	printf("Digite outro numero: ");
	scanf("%d", &num2);
	system("cls");
	printf("Escolha uma das opcoes abaixo: \n");
	printf("1- Soma;\n2- Subtracao;\n3- Multiplicacao;\n4- Divisao;\n");
	printf("Digite o numero da opcao: ");
	scanf("%d", &escolha);
	switch(escolha){
		case 1 : printf("%d", num1 + num2); break;
		case 2 : printf("%d", num1 - num2); break;
		case 3 : printf("%d", num1 * num2); break;
		case 4 : printf("%d", num1 / num2); break;
	}
	return 0;
}