#include <stdio.h>
#include <math.h>

int main(){
	
	float numero;
	float quadrado;
	float cubo;
	float raiz_quadrada;
	float raiz_cubica;
	
	printf("Digite um numero maior que 0: ");
	scanf("%f", &numero);
	
	quadrado = numero * numero;
	cubo = numero * numero * numero;
	raiz_quadrada = sqrt(numero);
	raiz_cubica = cbrt(numero);
	
	printf("\nO numero ao quadrado e: %.2f ", quadrado);
	printf("\nO nummero ao cubo e: %.2f", cubo);
	printf("\nA raiz quadrada do numero e: %.2f", raiz_quadrada);
	printf("\nA raiz cubica do numero e: %.2f", raiz_cubica);
	
	return 0;
}
