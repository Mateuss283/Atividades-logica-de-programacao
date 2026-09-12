#include <stdio.h>

int main(){
	
	float pes;
	float polegadas;
	float jardas;
	float milhas;
	
	printf("Digite a medida em pes: ");
	scanf("%f", &pes);
	
	polegadas = pes * 12;
	jardas = pes / 3;
	milhas = jardas / 1760;
	
	printf("\nO valor digitado em polegadas e: %.2f", polegadas);
	printf("\nO valor digitado em jardas e: %.2f", jardas);
	printf("\nO valor digitado em milhas e: %.2f", milhas);
	
	return 0;
}
