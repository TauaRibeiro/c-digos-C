#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

int somatorio(int num);

int main(){
    setlocale(LC_ALL, "Portuguese");
    
	int num;
	
	printf("Digite o número que irá calcular o fatorial: ");
	scanf("%d", &num);
	printf("O somátorio será: %d", somatorio(num));
	return 0;
}

int somatorio(int num){
	int soma;
	
	if(num <= 1){
		return (1);
	}
	else{
		soma = num + somatorio(num-1);
		return (soma);
	}
	
}
