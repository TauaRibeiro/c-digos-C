#include <stdio.h>
#include <stdlib.h>
int main(){
	int quantidade = 0;
	float media = 0, num;
	char parar;
	while(1){
		printf("Digite um numero: ");
		scanf("%f", &num);
		media += num;
		quantidade ++;
		while(getchar() != '\n');
		printf("Deseja parar? [S/N]: ");
		scanf("%c", &parar);
		if(parar == 'S' || parar == 's'){
			break;
		}
	}
	printf("%.2f", media/quantidade);
	return 0;
}