#include <stdio.h>
#include <stdlib.h>
int main(){
	int num, soma = 0, decimal = 1, digitos = 1;
	printf("Digite um numero: ");
	scanf("%d", &num);
	while(num % decimal != num){
		digitos++;
		decimal *= 10;
	}
	for(int i = 0; i < digitos; i++){
		soma += num/decimal;
		num = num % decimal;
		decimal /= 10;
	}
	printf("%d", soma);
	return 0;
}