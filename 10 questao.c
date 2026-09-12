#include <stdio.h>

int main(){
	
	float altura;
	float peso;
	float imc;
	
	printf("Digite sua altura: ");
	scanf("%f", &altura);
	
	printf("Digite seu peso: ");
	scanf("%f", &peso);
	
	imc = peso / (altura * altura);
	
	if(imc < 18.5){
		printf("\nAbaixo do peso");
	}else if(imc <= 25){
		printf("\nPeso normal");
	}else if(imc <= 30){
		printf("\nAcima do peso");
	}else{
		printf("\nObeso");
	}
	
	return 0;
}
