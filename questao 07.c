#include <stdio.h>

int main () {
	
	float salario_base;
	float salario_final;
	
	printf("Digite seu salario base: ");
	scanf("%f", &salario_base);
	
	salario_base = salario_base + 50;
	
	salario_final = salario_base - (salario_base * 5 / 100);
	
	printf("\nSeu salario final e: R$%.2f", salario_final);
	
	return 0;
	
}
