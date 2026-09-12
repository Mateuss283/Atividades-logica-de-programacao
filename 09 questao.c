#include <stdio.h>

int main(){
	
	float altura;
	char sexo;
	float pesoIdeal;
	
	printf("Digite sua altura: ");
	scanf("%f", &altura);
	
	printf("Digite seu sexo(M ou F): ");
	scanf(" %c", &sexo);
	
	if(sexo == 'M'){
		pesoIdeal = (72.7 * altura) - 58;
		
	}else if(sexo == 'F'){
		pesoIdeal = (62.1 * altura) - 44.7;
	}
	
	printf("\nSeu peso ideal e: %.2f", pesoIdeal);
	
	return 0;
	
}
