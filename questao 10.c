#include <stdio.h>

int main (){
	
	float raio;
	float area;
	
	printf("Digite o raio do circulo: ");
	scanf("%f", &raio);
	
	area = 3.14159 * raio * raio;
	
	printf("\nA area do circulo e: %.2f", area);
	
	return 0;
		
}
