#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(){
    system("cls");
    setlocale(LC_ALL, "portuguese");

    int *ptr = (int *)malloc(5*sizeof(int));

    for(int i = 0; i < 5; i++){
        printf("Digite o %d° número: ", i+1);
        scanf("%d", &ptr[i]);
    }

    for(int i = 0; i < 5; i++){
        printf("%d;\n", ptr[i]);
    }

    free(ptr);
    
    return 0;
}
