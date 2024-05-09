#include <stdio.h>
#include <stdlib.h>
int main(){
	int inicio, fim;
	printf("Digite o numero que inicie o intervalo: ");
	scanf("%d", &inicio);
	printf("Digite o numero que termine o intervalo: ");
	scanf("%d", &fim);
	for(int i = inicio; i <= fim; i++){
		if(i == 2 || i == 3 || i ==5){
			printf("%d;\n", i);
		}
		else if(i % 2 != 0 && i % 5 !=0 && i % 3 != 0 && i != 1){
			printf("%d;\n", i);
		}
	}
	return 0;
}