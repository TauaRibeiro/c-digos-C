#include <stdio.h>
int main(){
	int escolha;
	float dinheiro;
	printf("Quantos reais voce tem? R$ ");
	scanf("%f", &dinheiro);
	printf("Para qual moeda voce gostaria de converter?\n");
	printf("1- Dolar;\n2- Euro;\n");
	printf("Digite o numero da opcao desejada: ");
	scanf("%d", &escolha);
	printf("A conversao sera para ");
	switch(escolha){
		case 1 :
		printf("%.2f", dinheiro/5.12);
		printf(" dolares.");
		break;
		case 2 : 
		printf("%.2f", dinheiro/5.47);
		printf(" euros.");
	}
}