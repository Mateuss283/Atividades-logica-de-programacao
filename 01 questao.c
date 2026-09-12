#include <stdio.h>

int main (){
	
	int n1, n2, n3;
	int soma;
	
	printf("Escreva o primeiro numero: ");
	scanf("%d", &n1);
	
	printf("Escreva o segundo numero: ");
	scanf("%d", &n2);
	
	printf("Escreva o terceiro numero: ");
	scanf("%d", &n3);
	
	soma = n1 + n2;
	
	if( soma < n3){
	printf("\nA soma dos dois primeiros numeros e menor que o numero 3");
    }else{
    	printf("\nA soma dos dois primeiros numeros e maior que o numero 3");
	}
	
	return 0;
}
