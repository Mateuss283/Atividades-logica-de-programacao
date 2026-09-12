#include <stdio.h>

int main (){
	
	float horas_trabalhadas;
	float valor_salario;
	float receber;
	float salario_bruto;
	float imposto;
	float salario_final;
	
	printf("Digite a quantidade de horas trabalhadas: ");
	scanf("%f", &horas_trabalhadas);
	
	printf("Digite o valor do salario minimo: ");
	scanf("%f", &valor_salario);
	
	receber = valor_salario / 2;
	
	salario_bruto = horas_trabalhadas * receber;
	
	imposto = salario_bruto * 0.03;
	
	salario_final = salario_bruto - imposto;
	
	printf("\nSeu salario final sera: %.2f", salario_final);
	
	return 0;

}
