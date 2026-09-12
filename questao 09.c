#include <stdio.h>

int main (){
	
	float base;
	float altura;
	float area;
	
	printf("Digite a base do triangulo: ");
	scanf("%f", &base);
	
	printf("Digite a altura do triangulo: ");
	scanf("%f", &altura);
	
	area = (base * altura)/2;
	
	printf("\nA area do triangulo e: %.2f", area);
	
	return 0;
	
}
