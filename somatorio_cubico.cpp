#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

int somatorio_cubico(int num);

int main(){
    setlocale(LC_ALL, "Portuguese");
    
	int num;
	
	printf("Digite o número que irá calcular o somatório cúbico: ");
	scanf("%d", &num);
	printf("O somátorio cúbico será: %d", somatorio_cubico(num));
	return 0;
}

int somatorio_cubico(int num){
	int soma, cubo = 1;
	
	if(num == 1){
		return 1;
	}
	else{
		for(int i = 0; i < 3; i++){
			cubo = num * cubo;
		}
		soma = cubo + somatorio_cubico(num-1);
		return soma;
	}
	
}
