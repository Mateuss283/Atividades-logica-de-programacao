#include <stdio.h>

int main(){
	
	float velocidade;
	float limite;
	float percentual;
	
	printf("Digite a velocidade maxima permitida da via: ");
	scanf("%f", &limite);
	
	printf("Digite a velocidade registrada do veiculo: ");
	scanf("%f", &velocidade);
	
	if(velocidade <= limite){
		printf("\nNao houve infracao.");
		
	}else{
		
		percentual = (velocidade - limite ) / limite;
		
		if(percentual <= 0.20){
			printf("\nInfracao media.");
			
		}else if(percentual <= 0.50){
			printf("\nInfracao grave.");
			
		}else{
			printf("\nInfracao gravissima.");
			
		}
		
	if(velocidade > 120){
		printf("\nVelocidade extremante elevada.");
	}	
		
	printf("\nLimite da via: %.2f", limite);
	printf("\nVelocidade registrada: %.2f", velocidade);
	printf("\nPercentual excedido: %.2f%%", percentual * 100);
	}
	
	return 0;
		
}
