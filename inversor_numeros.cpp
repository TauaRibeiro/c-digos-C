#include <stdio.h>
#include <stdlib.h>
int main(){
	int num, soma = 0, decimal = 1, digitos = 1;
	float inv_num;
	printf("Digite um numero: ");
	scanf("%d", &num);
	while(num % decimal != num){
		digitos++;
		decimal *= 10;
	}
	for(int i = 0; i < digitos; i++){
		if(i == 0){
			inv_num = (num/decimal)/10;
			num = num % decimal;
		}
		else{
			inv_num = (inv_num+(num/decimal))/10;
			num = num % decimal;
		}
		decimal /= 10;
	}
	for(int i = 1; i < digitos; i++){
		inv_num *= 10;
	}
	printf("o inverso dele sera %.0f", inv_num);
	return 0;
}