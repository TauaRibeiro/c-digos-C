#include <stdio.h>
int main(){
	int idade;
	printf("Digite a faixa etaria em que se ecaixa: ");
	printf("\n1- 0 - 12 anos;\n2- 13 - 17 anos;\n3- 18 - 64 anos;\n4- 65+ anos;\n");
	printf("Digite o numero da sua escolha: ");
	scanf("%d", &idade);
	switch(idade){
		case 1 : printf("Infantil"); break;
		case 2 : printf("Adolescente"); break;
		case 3 : printf("Adulto"); break;
		case 4 : printf("Idoso"); break;
	}
	return 0;
}