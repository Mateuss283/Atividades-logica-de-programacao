#include <stdio.h>

int main(){
	
	float preco;
	float precoFinal;
	int codigo;
	
	printf("Digite o preco do produto: ");
	scanf("%f", &preco);
	
	printf("Digite o codigo da compra: ");
	scanf("%d", &codigo);
	
	if(codigo == 1){
		precoFinal = preco - (preco * 0.10);
		
	}else if(codigo == 2){
		precoFinal = preco - (preco * 0.15);
		
	}else if(codigo == 3){
		precoFinal = preco;
		
	}else if(codigo == 4){
		precoFinal = preco + (preco * 0.10);
	}
	
	printf("\nO valor final da compra e:  R$%.2f", precoFinal);
	
	return  0;
	
}
