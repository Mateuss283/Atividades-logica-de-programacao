#include <stdio.h>

int main (){
	
	int num; 
	
	printf("Escreva o numero: ");
	scanf("%d", &num);
	
	if(num % 2 == 0){
	printf("O numero e par");
    }else {
    	printf("\nO numero e impar");
    	
	}
	
	return 0;
}
