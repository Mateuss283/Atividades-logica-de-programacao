#include <stdio.h>

int main(){
	
	int num;
	
	printf("Digite um numero: ");
	scanf("%d", &num);
	
	if(num % 2 == 0){
		num = num + 5;
	}else{
		num = num + 8;
	}
	
	printf("\nO resultado da operecao e: %d", num);
	
	return 0;
}
