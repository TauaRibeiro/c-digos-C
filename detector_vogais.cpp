#include <stdio.h>
int main(){
	char letra;
	printf("Digite uma letra: ");
	scanf("%c", &letra);
	switch(letra){
		case 'a' : printf("E uma vogal"); break;
		case 'e' : printf("E uma vogal"); break;
		case 'i' : printf("E uma vogal"); break;
		case 'o' : printf("E uma vogal"); break;
		case 'u' : printf("E uma vogal"); break;
		case 'A' : printf("E uma vogal"); break;
		case 'E' : printf("E uma vogal"); break;
		case 'O' : printf("E uma vogal"); break;
		case 'I' : printf("E uma vogal"); break;
		case 'U' : printf("E uma vogal"); break;
		default : printf("E uma consoante");
	}
	return 0;
}