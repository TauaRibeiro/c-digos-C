#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define num_eletro 5

struct eletro{
	char nome[16];
	float consumo;
};

void linha(char tipo, int comprimento){
	printf("\n");
	for(int i = 0; i < comprimento; i++){
		printf("%c", tipo);
	}
	printf("\n");
}
int main(){
	system("cls");
	setlocale(LC_ALL, "Portuguese");
	
	struct eletro equipamento[num_eletro];
	float consumo_total = 0, potencia, tempoh, consumo;
	int tempod;
	
	printf("Digite o período de tempo em dias: ");
	scanf("%d", &tempod);
	
	for(int i = 0; i < num_eletro; i++){
        system("cls");

		printf("Digite o nome do %d° eletrodoméstico: ", i+1);
		scanf(" %15[^\n]s", equipamento[i].nome);
		
		printf("Digite a potência do equipamento: ");
		scanf("%f", &potencia);
		
		printf("Digite por quantas horas por dia o equipamento fica funcionando: ");
		scanf("%f", &tempoh);
		
		consumo = potencia*tempoh*tempod;
			
		consumo_total += consumo;
			
		equipamento[i].consumo = consumo;
	}

    system("cls");
	
	linha('=', 50);
	
	for(int i = 0; i < num_eletro; i++){
		printf("ELETRODOMÉSTICO: %s\nCONSUMO RELATIVO: %.2f%%", equipamento[i].nome,
        (equipamento[i].consumo/consumo_total)*100);
		if(i < num_eletro-1){
			linha('-', 50);
		}
	}
	linha('=', 50);
    printf("\nCONSUMO TOTA - > %.2f Kw/h\n", consumo_total);
    linha('=', 50);
	
	
	return 0;
} 
