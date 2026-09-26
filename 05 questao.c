#include <stdio.h>

int main(){
	
	int numero;
	int soma = 0;
	
	printf("Digite numero: ");
	scanf("%d", &numero);
	
	for(int contador = 1; contador <= numero; contador++){
		soma = soma + contador;
		
	}
	
	printf("\nA soma de %d numeros seguidos e: %d", numero, soma);
	
	return 0;
}
