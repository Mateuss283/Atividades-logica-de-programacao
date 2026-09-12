#include <stdio.h>

int main (){
	
	int numero;
	int resultado;
	
	printf("Digite o numero: ");
	scanf("%d", &numero);
	
	if(numero > 0){
		resultado = numero * 2;
	}else{
		resultado = numero * 3;
	}
	
	printf("\nO resultado e: %d", resultado);
	
	return 0;
}
