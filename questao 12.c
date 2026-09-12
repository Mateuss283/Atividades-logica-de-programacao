#include <stdio.h>
#include <math.h>

int main (){
	
	float n1, n2;
	float resultado;
	
	printf("Digite o primeiro numero: ");
	scanf("%f", &n1);
	
	printf("Digite o segundo numero: ");
	scanf("%f", &n2);
	
	resultado = pow(n1, n2);
	
	printf("\nO resultado de %.2f elevado a %.2f e: %.2f", n1, n2, resultado);
	
	return 0;
}
