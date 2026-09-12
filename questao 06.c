#include <stdio.h>

int main (){
	
	float salario;
	float novo_salario;
	
	printf("Digite seu salario: ");
	scanf("%f", &salario);
	
	novo_salario = salario + (salario * 5 / 100 );
	 
	novo_salario = novo_salario - (novo_salario * 7 / 100);
	
	printf("\nSeu salario final e: R$%.2f", novo_salario);
	
	return 0;
}
