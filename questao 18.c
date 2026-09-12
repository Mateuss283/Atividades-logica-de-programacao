#include <stdio.h>

int main(){
	
	float peso_kilo;
	float peso_grama;
	float racao_dada;
	float restante;
	
	printf("Digite o peso do saco em kilos: ");
	scanf("%f", &peso_kilo);
	
	printf("Quantas gramas e oferecida para cada gato por dia? ");
	scanf("%f", &racao_dada);
	
	peso_grama = peso_kilo * 1000;
	
	restante = peso_grama - (racao_dada * 5);
	
	printf("\nA quantidade restante apos 5 dias sera: %.2f gramas", restante);
}
