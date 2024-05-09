#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
int main(){
	char palavra[] = "SENAI";
	char adivinhacao[20];
	while(1){
		printf("Digite uma palavra: ");
		scanf("%s", adivinhacao);
		system("cls");
		for(int i = 0; i < 20; i++){
			adivinhacao[i] = toupper(adivinhacao[i]);
		}
		if(strcmp(palavra, adivinhacao) == 0){
			printf("Voce acertou!!");
			break;
		}
		printf("Voce errou, tente novamente...\n");
	}
	return 0;
}