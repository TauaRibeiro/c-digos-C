#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

int verificarTriangulo(int lados[3]);

int main(){
    setlocale(LC_ALL, "Portuguese");
    
    int lados[3];
    
    for(int i = 0; i < 3; i++){
    	printf("Digite o %d° lado: ", i+1);
    	scanf("%d" , &lados[i]);
	}
	
	printf("%i", verificarTriangulo(lados));
	
	return 0;
}

int verificarTriangulo(int lados[3]){
	if(lados[0] < lados[1] + lados[2] && lados[1] < lados[2] + lados[0] && lados[3] < lados[0] + lados[1]){
		return 1;
	}
	else{
		return 0;
	}
}
