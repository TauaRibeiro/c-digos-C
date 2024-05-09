#include <stdio.h>
#include <stdlib.h>
int main(){
	int anterior = 1, proximo = 2, meio = 1;
	for(int i = 1; i < 11; i++){
		if(i < 3){
			printf((i == 1) ? "%d" : ", %d", anterior);
		}
		else if(i == 3){
			printf(", %d", proximo);
		}
		else{
			anterior = proximo;
			proximo = meio + proximo;
			meio = anterior;
			printf(", %d", proximo);
		}
	}
	return 0;
}