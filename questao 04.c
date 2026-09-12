#include <stdio.h>

int main (){
	
	float salario;
	float aumento;
	
	printf("Digite seu salario: ");
	scanf("%f", &salario);
	
	
	aumento = salario * 1.25;
	
	printf("\nSeu salario recebeu um ajuste de 25%% de aumento e foi para: R$%.2f", aumento);
	
	 return 0;
	
}
