#include <stdio.h>

int main(){
	
	float preco_fabrica;
	float percentual_lucro;
	float percentual_impostos;
	float lucro;
	float impostos;
	float preco_final;
	
	printf("Digite o preco de fabrica do carro: ");
	scanf("%f", &preco_fabrica);
	
	printf("Digite o percentual do lucro do distribuidor: ");
	scanf("%f", &percentual_lucro);
	
	printf("Digite a taxa dos impostos: ");
	scanf("%f", &percentual_impostos);
	
	lucro = preco_fabrica * percentual_lucro/100;
	impostos = preco_fabrica * percentual_impostos/100;
	preco_final = preco_fabrica + lucro + impostos;
	
	printf("\nO valor do lucro do distribuidor e: %.2f", lucro);
	printf("\nO valor do imposto e: %.2f", impostos);
	printf("\nO preco final do veiculo e: %.2f", preco_final);
	
	return 0;
	
}
