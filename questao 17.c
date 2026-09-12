#include <stdio.h>

int main(){
	
	float salario;
	float cpmf;
	float retirada1;
	float retirada2;
	float conta;
	
	printf("Qual foi o valor depositado na conta? R$");
	scanf("%f", &salario);
	
	printf("Qual foi o valor emitido do primeiro cheque? R$");
	scanf("%f", &retirada1);
	
	printf("Qual foi o valor emitido do segundo cheque? R$");
	scanf("%f", &retirada2);
	
	cpmf = 0.0032;
	
	conta = salario - retirada1 - retirada2;
	
    conta = conta - (retirada1 * cpmf) - (retirada2 * cpmf);
	
	printf("\nO saldo restante da sua conta e: R$%.2f", conta);

	return 0;
}
