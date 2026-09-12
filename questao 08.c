#include <stdio.h>

int main (){
	
	float deposito;
	float juros;
	float rendimento;
	float valor_final;
	
	printf("Digite o valor do deposito: ");
	scanf("%f", &deposito);
	
	printf("Digite a taxa de juros: ");
	scanf("%f", &juros);
	
	rendimento = deposito * juros / 100;
    valor_final = deposito + rendimento;
	
	
	printf("\nO rendimento foi R$%.2f e o valor final ficou R$%.2f", rendimento, valor_final);
	
	return 0;
	
}
