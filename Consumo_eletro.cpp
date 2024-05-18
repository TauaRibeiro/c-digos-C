#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define num_eletro 5
//Definição da estrutura eletro;
struct eletro{
	char nome[16];
	float consumo;
};
//Definição da estrutura registro;
struct registro{
	float consumo_total;
	struct eletro eletro[num_eletro];
};
//Prototipagem das funções;
void leitura(struct registro *reg);
void linha(char tipo, int comprimento);
float calculo(struct registro *reg, int index);

int main(){
	system("cls");
	setlocale(LC_ALL, "Portuguese");
	//Declaração da estrutura do tipo registro referenciado como reg;
	struct registro reg;
	//Chamada da fução leitura, recebendo o endereço de reg;
	leitura(&reg);

    system("cls");
	//Chamada da função linha;
	linha('=', 50);
	//Saída de dados;
	for(int i = 0; i < num_eletro; i++){
		printf("ELETRODOMÉSTICO: %s\nCONSUMO RELATIVO: %.2f%%", reg.eletro[i].nome, calculo(&reg, i));
		if(i < num_eletro-1){
			linha('-', 50);
		}
	}
	linha('=', 50);
    printf("CONSUMO TOTAl - > %.2f Kw/h", reg.consumo_total);
    linha('=', 50);
	
	
	return 0;
} 
//Função responsável por imprimir uma linha formatada;
void linha(char tipo, int comprimento){
	printf("\n");
	for(int i = 0; i < comprimento; i++){
		printf("%c", tipo);
	}
	printf("\n");
}
//Função responsável pela leitura de dados;
void leitura(struct registro *reg){
	float potencia, tempoh;
	int tempod;
	
	reg->consumo_total = 0;
	
	printf("Digite o período de tempo em dias: ");
	scanf("%d", &tempod);
	
	for(int i = 0; i < num_eletro; i++){
        system("cls");

		printf("Digite o nome do %d° eletrodoméstico: ", i+1);
		scanf(" %15[^\n]s", reg->eletro[i].nome);
		
		printf("Digite a potência do equipamento: ");
		scanf("%f", &potencia);
		
		printf("Digite quantas horas por dia o equipamento fica funcionando: ");
		scanf("%f", &tempoh);
		
		reg->eletro[i].consumo = potencia*tempoh*tempod;
			
		reg->consumo_total += reg->eletro[i].consumo;
	}

}
//Função responsável pelo cálculo do consumo relativo;
float calculo(struct registro *reg, int index){
	float porcentagem;

	porcentagem = reg->eletro[index].consumo/reg->consumo_total;

	return porcentagem*100;
}
