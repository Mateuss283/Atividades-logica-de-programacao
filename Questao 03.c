#include <stdio.h>

struct Funcionario{
	int codigo;
	char nome[50];
	char cargo[50];
	float salarioBase;
	int horasExtras;
};

void cadastrarFuncionario(struct Funcionario *funcionario){
	
	printf("Digite o codigo do funcionario: ");
	scanf("%d", &funcionario->codigo);
	
	printf("Digite o nome: ");
	scanf(" %49[^\n]", funcionario->nome);
	
	printf("Digite o cargo: ");
	scanf(" %49[^\n]", funcionario->cargo);
	
	printf("Digite o salario-base: ");
	scanf("%f", &funcionario->salarioBase);
	
	printf("Digite a quantidade de horas extras: ");
	scanf("%d", &funcionario->horasExtras);
	
}

float calcularValorHora(float salarioBase){
	
	float valorHora = salarioBase / 160;
	
	return valorHora;
}

float calcularHoraExtra(float valorHora){
	
	float valorExtra = valorHora * 1.5;
	
	return valorExtra;
}

float calcularSalarioBruto(float salarioBase, int horasExtras, float valorHoraExtra){
	
	float salarioBruto = salarioBase + (horasExtras * valorHoraExtra);
	
	return salarioBruto;
}

float calcularDesconto(float salarioBruto){
	
	float desconto = salarioBruto * 0.10;
	
	return desconto;
}

float calcularSalarioLiquido(float salarioBruto, float desconto){
	
	float salarioLiquido = salarioBruto - desconto;
	
	return salarioLiquido;
}

void listarFuncionarios(struct Funcionario funcionarios[], int quantidade){
	
	if(quantidade == 0){
		printf("\nNenhum funcionario cadastrado.\n");
		return;
	}
	
	for(int i = 0; i < quantidade; i++){
		
		float valorHora = calcularValorHora(funcionarios[i].salarioBase);
		float valorHoraExtra = calcularHoraExtra(valorHora);
		float salarioBruto = calcularSalarioBruto(funcionarios[i].salarioBase, funcionarios[i].horasExtras, valorHoraExtra);
		float desconto = calcularDesconto(salarioBruto);
		float salarioLiquido = calcularSalarioLiquido(salarioBruto, desconto);
		
		printf("\n===== FUNCIONARIO %d =====\n", i + 1);
		printf("Codigo: %d\n", funcionarios[i].codigo);
		printf("Nome: %s\n", funcionarios[i].nome);
		printf("Cargo: %s\n", funcionarios[i].cargo);
		printf("Salario-base: R$ %.2f\n", funcionarios[i].salarioBase);
		printf("Horas extras: %d\n", funcionarios[i].horasExtras);
		printf("Salario bruto: R$ %.2f\n", salarioBruto);
		printf("Desconto: R$ %.2f\n", desconto);
		printf("Salario liquido: R$ %.2f\n", salarioLiquido);
	}
}

float calcularFolhaTotal(struct Funcionario funcionarios[], int quantidade){
	
	float total = 0;
	
	for(int i = 0; i < quantidade; i++){
		
		float valorHora = calcularValorHora(funcionarios[i].salarioBase);
		float valorHoraExtra = calcularHoraExtra(valorHora);
		float salarioBruto = calcularSalarioBruto(funcionarios[i].salarioBase, funcionarios[i].horasExtras, valorHoraExtra);
		float desconto = calcularDesconto(salarioBruto);
		float salarioLiquido = calcularSalarioLiquido(salarioBruto, desconto);
		
		total += salarioLiquido;
	}
	
	return total;
}

int maiorSalarioLiquido(struct Funcionario funcionarios[], int quantidade){
	
	int posicao = 0;
	
	float valorHora = calcularValorHora(funcionarios[0].salarioBase);
	float valorHoraExtra = calcularHoraExtra(valorHora);
	float salarioBruto = calcularSalarioBruto(funcionarios[0].salarioBase, funcionarios[0].horasExtras, valorHoraExtra);
	float desconto = calcularDesconto(salarioBruto);
	float maior = calcularSalarioLiquido(salarioBruto, desconto);
	
	for(int i = 1; i < quantidade; i++){
		
		valorHora = calcularValorHora(funcionarios[i].salarioBase);
		valorHoraExtra = calcularHoraExtra(valorHora);
		salarioBruto = calcularSalarioBruto(funcionarios[i].salarioBase, funcionarios[i].horasExtras, valorHoraExtra);
		desconto = calcularDesconto(salarioBruto);
		
		float salarioLiquido = calcularSalarioLiquido(salarioBruto, desconto);
		
		if(salarioLiquido > maior){
			maior = salarioLiquido;
			posicao = i;
		}
	}
	
	return posicao;
}
int main(){
	
	int quantidade = 0;
	struct Funcionario funcionarios[8];
	
	int opcao;
	
	do{
		
		printf("\n===== FUNCIONARIOS =====\n");
		printf("1 - Cadastrar funcionario\n");
		printf("2 - Listar funcionarios\n");
		printf("3 - Maior salario liquido\n");
		printf("4 - Custo total da folha\n");
		printf("0 - Sair\n");
		printf("Escolha: ");
		scanf("%d", &opcao);
		
		if(opcao == 1){
			
			if(quantidade < 8){
				cadastrarFuncionario(&funcionarios[quantidade]);
				quantidade++;
				
			}else{
				printf("Limite de funcionarios atingido!\n");
			}
		}
		
		if(opcao == 2){
			listarFuncionarios(funcionarios, quantidade);
		}
		
		if(opcao == 3){
	
	if(quantidade == 0){
		printf("Nenhum funcionario cadastrado.\n");
	}else{
		
		int posicao = maiorSalarioLiquido(funcionarios, quantidade);
		
		printf("\n===== MAIOR SALARIO LIQUIDO =====\n");
		printf("Codigo: %d\n", funcionarios[posicao].codigo);
		printf("Nome: %s\n", funcionarios[posicao].nome);
		printf("Cargo: %s\n", funcionarios[posicao].cargo);
		
		float valorHora = calcularValorHora(funcionarios[posicao].salarioBase);
		float valorHoraExtra = calcularHoraExtra(valorHora);
		float salarioBruto = calcularSalarioBruto(funcionarios[posicao].salarioBase, funcionarios[posicao].horasExtras, valorHoraExtra);
		float desconto = calcularDesconto(salarioBruto);
		float salarioLiquido = calcularSalarioLiquido(salarioBruto, desconto);
		
		printf("Salario liquido: R$ %.2f\n", salarioLiquido);
	}
}

if(opcao == 4){
	
	if(quantidade == 0){
		printf("Nenhum funcionario cadastrado.\n");
	}else{
		
		float total = calcularFolhaTotal(funcionarios, quantidade);
		
		printf("Custo total da folha: R$ %.2f\n", total);
	}
}
		
	}while(opcao != 0);
	
	return 0;
}
