#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <ctype.h>
struct dados{
       char nome[100], cidade[100], email[100], endereco[100];
       long int cep;
       int dia, mes, ano;
    };
       
int veri_data(struct dados d);
int dias_mes(int mes);
void linha(void);

int main(){
    system("cls");
    setlocale(LC_ALL, "PORTUGUESE");
    
    struct dados user;
    char dados_erros[3][50] = {"NOME", "DATA DE NASCIMENTO", "CEP"};
    int erros[3] = {0}, veri_erro = 0;
    
    printf("Digite o seu nome: ");
    scanf(" %99[^\n]s", user.nome);
    
    if(user.nome == '\0'){
    	veri_erro = 1;
    	erros[0]++;
	}
    printf("Digite a sua data de nascimento (dd/mm/aaaa): ");
    scanf("%d/%d/%d", &user.dia, &user.mes, &user.ano);
       
    if(!veri_data(user)){
    	veri_erro = 1;
    	erros[1]++;
    }
    
    printf("Digite o seu email: ");
    scanf(" %99[^\n]s", user.email);
    
    system("cls");
    
    printf("Digite o nome da cidade me que reside: ");
    scanf(" %99[^\n]s", user.cidade);
    
    printf("Digite o endereço em que reside: ");
    scanf(" %99[^\n]s", user.endereco);
    
    printf("Digite os números do CEP em que reside: ");
    scanf("%ld", &user.cep);
    
	if(user.cep >= 100000000 || user.cep <= 999999){
		veri_erro = 1;
		erros[2]++;
	}
    
	system("cls");
    
    linha();
    if(veri_erro == 1){
    	printf("INFORMAÇÕES ERRADAS!!\n");
        for(int i = 0; i < 3; i++){
            if(erros[i] == 1){
                printf("%s;\n", dados_erros[i]);
            }
        }
    	
	}
    else{
        printf("NOME: %s\nDATA DE NASCIMENTO: %d/%d/%d\nEMAIL: %s\n", user.nome, user.dia, user.mes,
        user.ano, user.email);
        printf("CIDADE: %s\nENDEREÇO: %s\nCEP: %ld", user.cidade, user.endereco, user.cep);
    }
    linha();
    return 0;
}

int veri_data(struct dados d){
    int valido = 1;
    
    if(2024 - d.ano >= 200 || 2024 - d.ano <= 0){
        valido--;
    }
    if(d.mes > 12 || d.mes < 1){
        valido--;
    }
    if(dias_mes(d.mes) < d.dia || d.dia < 0){
        valido--;
    }
    
    return valido;
}


int dias_mes(int mes){
    int dias[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    
    return dias[mes-1];
}
void linha(void){
	printf("\n========================================================\n");
}
