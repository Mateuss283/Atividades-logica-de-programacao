#include <stdio.h>

struct Produto{
	int codigo;
	char nome[50];
	float preco;
	int quantidade;
};

int verificarProduto(struct Produto produtos[], int quantidade, int codigo);

void cadastrarProduto(struct Produto *produto, struct Produto produtos[], int quantidade){
	
	printf("Digite o codigo do produto: ");
	scanf("%d", &produto->codigo);
	
	while(verificarProduto(produtos, quantidade, produto->codigo)){
		printf("Codigo ja cadastrado! Digite outro: ");
		scanf("%d", &produto->codigo);
	}
	
	printf("Digite o nome do produto: ");
	scanf(" %49[^\n]", produto->nome);
	
	printf("Digite o preco: ");
	scanf("%f", &produto->preco);
	
	printf("Digite a quantidade: ");
	scanf("%d", &produto->quantidade);	
}

int verificarProduto(struct Produto produtos[], int quantidade, int codigo){
	
	for(int i = 0; i < quantidade; i++){
		
		if(produtos[i].codigo == codigo){
			return 1;
		}
	}
		return 0;
}

void listarProduto(struct Produto produtos[], int quantidade){
	
	if(quantidade == 0){
		printf("\nNenhum produto cadastrado.\n");
		return;
	}
	
	for(int i = 0; i < quantidade; i++){
	
	printf("\n===== PRODUTO %d =====\n", i + 1);
	printf("Codigo: %d\n", produtos[i].codigo);
	printf("Nome: %s\n", produtos[i].nome);
	printf("Preco: %.2f\n", produtos[i].preco);
	printf("Quantidade: %d\n", produtos[i].quantidade);
	}
}		

void reporEstoque(struct Produto *produto){
	
	int quantidade;
	
	printf("Digite a quantidade para repor: ");
	scanf("%d", &quantidade);
	
	produto->quantidade += quantidade;
	
	printf("Estoque atualizado.\n");
}

int encontrarProduto(struct Produto produtos[], int quantidade, int codigo){
	
	for(int i = 0; i < quantidade; i++){
		
		if(produtos[i].codigo == codigo){
			return i;
		}

	}
	
	return -1;
}

void registrarVenda(struct Produto *produto){
	
	int quantidade;
	
	printf("Digite a quantidade para vender: ");
	scanf("%d", &quantidade);
	
	if(quantidade <= produto->quantidade){
		
		produto->quantidade -= quantidade;
		
		printf("Venda registrada.\n");
		
	}else{
		printf("quantidade em estoque insuficiente.\n");
	}
}

void consultarProduto(struct Produto produtos[], int quantidade){
	
	int codigo;
	
	printf("Digite o codigo do produto: ");
	scanf("%d", &codigo);
	
	int posicao = encontrarProduto(produtos, quantidade, codigo);
	
	if(posicao != -1){
		
		printf("Codigo: %d\n", produtos[posicao].codigo);
		printf("Nome: %s\n", produtos[posicao].nome);
		printf("Preco: %.2f\n", produtos[posicao].preco);
		printf("Quantidade: %d\n", produtos[posicao].quantidade);

	}else{
		printf("Codigo nao existe.\n");
	}
}

float valorTotalEstoque(struct Produto produtos[], int quantidade){
	
	float total = 0;
	
	for(int i = 0; i < quantidade; i++){
		total += produtos[i].preco * produtos[i].quantidade;
	}
	
	return total;
}

int maiorValorEstoque(struct Produto produtos[], int quantidade){
	
	int posicao = 0;
	float maior = produtos[0].preco * produtos[0].quantidade;
	
	for(int i = 1; i < quantidade; i++){
		
		float valor = produtos[i].preco * produtos[i].quantidade;
		
		if(valor > maior){
			maior = valor;
			posicao = i;
		}
	}
	
	return posicao;
}

int main(){
	
	int quantidade = 0; 
	
	struct Produto produtos[15];
	
	int opcao;
	int codigo;
	
	do{
		
		printf("\n===== PAPELARIA =====\n");
		printf("1 - Cadastrar produto\n");
		printf("2 - Listar produto\n");
		printf("3 - Repor estoque\n");
		printf("4 - Registrar venda\n");
		printf("5 - Consultar produto\n");
		printf("6 - Valor total do estoque\n");
		printf("7 - Produto com maior valor em estoque\n");
		printf("0 - Sair\n");
		printf("Escolha: ");
		scanf("%d", &opcao);
			
			if(opcao == 1){
				
				if(quantidade < 15){
					cadastrarProduto(&produtos[quantidade], produtos, quantidade);
					quantidade++;
					
				}else{
					printf("Limite de produtos atingido!\n");
				}
			}
			
			if(opcao == 2){
				listarProduto(produtos, quantidade);
			}
			
			if(opcao == 3){
				
				printf("Digite o codigo do produto: ");
				scanf("%d", &codigo);
				
				int posicao = encontrarProduto(produtos, quantidade, codigo);
				
				if(posicao != -1){
					reporEstoque(&produtos[posicao]);
				}else{
					printf("Produto nao encontrado.\n");
				}
			}
			
			if(opcao == 4){
				
				printf("Digite o codigo do produto: ");
				scanf("%d", &codigo);
				
				int posicao = encontrarProduto(produtos, quantidade, codigo);
				
				if(posicao != -1){
					registrarVenda(&produtos[posicao]);
					
				}else{
					printf("Produto não encontrado.\n");
				}
			}
			
			if(opcao == 5){
				consultarProduto(produtos, quantidade);
			}
			
			if(opcao == 6){
				
				float total = valorTotalEstoque(produtos, quantidade);
				
				printf("Valor total do estoque: R$ %.2f\n", total);
			}
			
			if(opcao == 7){
	
	if(quantidade == 0){
		printf("Nenhum produto cadastrado.\n");
	}else{
		int posicao = maiorValorEstoque(produtos, quantidade);
		
		printf("\n===== MAIOR VALOR EM ESTOQUE =====\n");
		printf("Codigo: %d\n", produtos[posicao].codigo);
		printf("Nome: %s\n", produtos[posicao].nome);
		printf("Preco: %.2f\n", produtos[posicao].preco);
		printf("Quantidade: %d\n", produtos[posicao].quantidade);
		printf("Valor total: R$ %.2f\n", produtos[posicao].preco * produtos[posicao].quantidade);
	}
}
			
	}while(opcao != 0);
	
	return 0;
}
