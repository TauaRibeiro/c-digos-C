#include <stdio.h>
#include <stdlib.h>
int main(){
	int num, fatorial = 1;
	printf("Digite um numero: ");
	scanf("%d", &num);
	for(int i = 1; i <= num; i++){
		fatorial *= i;
	}
	printf("%d", fatorial);
	return 0;
}