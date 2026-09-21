#include <stdio.h>

int main(){
	
	int numero;
	int contador = 1;
	int res;
	
	printf("Digite um numero: ");
	scanf("%d", &numero);
	
	printf("\n=========================");
	while(contador <= 10){
	
	res = numero * contador;
	printf("%d x %d = %d\n", numero, contador, res);
	contador++;
}

}
