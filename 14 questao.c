#include <stdio.h>

int main(){
	
	int codigo;
	
	printf("============= CARDAPIO ==============\n");
	printf("1 - Hamburguer com fritas - R$28,00\n");
	printf("2 - File de frango grelhado - R$32,00\n");
	printf("3 - Lasanha a bolonhesa - R$35,00\n");
	printf("4 - File de peixe com arroz - R$42,00\n");
	printf("5 - Salada especial - R$25,00\n");
	
	printf("\nDigite o codigo do prato  desejado: ");
	scanf("%d", &codigo);
	
	switch(codigo){
		
		case 1:
			printf("\nSeu pedido sera - Hamburguer com fritas - R$28,00");
			break;
		
		case 2:
			printf("\nSeu pedido sera - File de frango grelhado - R$32,00");
			break;
			
		case 3:
			printf("\nSeu pedido sera - Lasanha a bolonhesa - R$35,00");
			break;	
		
		case 4:
			printf("\nSeu pedido sera - File de peixe com arroz - R$42,00");
			break;
		
		case 5:
		printf("\nSeu pedido sera - Salada especial - R$25,00");
		break;
		
		default:
			printf("\nOpcao invalidade");
	} 
	
	return 0;
	
}
