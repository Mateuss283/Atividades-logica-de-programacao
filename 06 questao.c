#include <stdio.h>

int main(){
	
	int num1, num2;
	
	printf("0 = falso / 1 = verdadeiro");
	printf("\nDigite o primeiro valor de 0 a 1: ");
	scanf("%d", &num1);
	
	printf("Digite o segundo valor de 0 a 1: ");
	scanf("%d", &num2);
	
	if(num1 == 1 && num2 == 1){
		printf("\nAmbos os valores sao verdadeiros");
	}else if(num1 == 0 && num2 == 0){
		printf("\nAmbos os valores sao falsos");
	}else{
		printf("\nUm valor e verdadeiro e outro e falso");
		}
	
	return 0;
	
}
