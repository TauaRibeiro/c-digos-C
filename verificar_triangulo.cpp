#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void triangulo(float lados[3]){
	if(lados[0] < lados[1] + lados[2] && lados[1] < lados[2] + lados[0] && lados[3] < lados[0] + lados[1]){
		
		if(lados[0] == lados[1] && lados[0] == lados[2]){
		printf("É equilátero.");
		}
		
		else if(lados[0] == lados[1] || lados[0] == lados[2] || lados[1] == lados[2]){
			printf("É isóceles.");
		}
		
		else{
			printf("É escaleno.");
		}
	}
	else{
		printf("Não é um triângulo...");;
	}
	
}

int main(){
    system("cls");
    setlocale(LC_ALL, "PORTUGUESE");
    
    float lados[3];
    
    for(int i = 0; i < 3; i++){
    	printf("Digite o valor do %d° lado: ", i+1);
    	scanf("%f", &lados[i]);
	}
	
	triangulo(lados);
    
    return 0;
}
