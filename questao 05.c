#include <stdio.h>

int main (){
	
	float salario;
	float novo_salario;
	float aumento;
	
	printf("Digite o quanto voce recebia: ");
	scanf("%f", &salario);
	
	printf("Quantos porcento seu salario ira aumentar? ");
	scanf("%f", &aumento);
	
	novo_salario = salario + (salario * aumento / 100);
	
	printf("\nSeu salario agora e: %.2f", novo_salario);
	
	return 0;
	
}
