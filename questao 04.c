
#include <stdio.h>

struct Produto{
    int codigo;
    char nome[50];
    float preco;
    int quantidade;
};

struct Venda{
    int codigoProduto;
    int quantidade;
    float valorTotal;
};

void cadastrarProduto(struct Produto *produto){
    printf("Digite o codigo do produto: ");
    scanf("%d", &produto->codigo);

    printf("Digite o nome do produto: ");
    scanf(" %49[^\n]", produto->nome);

    printf("Digite o preco do produto: ");
    scanf("%f", &produto->preco);

    printf("Digite a quantidade em estoque: ");
    scanf("%d", &produto->quantidade);
}

void listarProdutos(struct Produto produtos[], int quantidade){
    if(quantidade == 0){
        printf("\nNenhum produto cadastrado.\n");
        return;
    }

    for(int i = 0; i < quantidade; i++){
        printf("\n===== PRODUTO %d =====\n", i + 1);
        printf("Codigo: %d\n", produtos[i].codigo);
        printf("Nome: %s\n", produtos[i].nome);
        printf("Preco: R$ %.2f\n", produtos[i].preco);
        printf("Quantidade: %d\n", produtos[i].quantidade);
    }
}

int encontrarProduto(struct Produto produtos[], int quantidade, int codigo){
    for(int i = 0; i < quantidade; i++){
        if(produtos[i].codigo == codigo){
            return i;
        }
    }

    return -1;
}

int registrarVenda(struct Produto produtos[], int quantidadeProdutos, struct Venda *venda){
    int codigo;
    int posicao;

    printf("Digite o codigo do produto: ");
    scanf("%d", &codigo);

    posicao = encontrarProduto(produtos, quantidadeProdutos, codigo);

    if(posicao == -1){
        printf("Produto nao encontrado!\n");
        return 0;
    }

    printf("Digite a quantidade que deseja vender: ");
    scanf("%d", &venda->quantidade);

    if(venda->quantidade > produtos[posicao].quantidade){
        printf("Estoque insuficiente!\n");
        return 0;
    }

    venda->codigoProduto = codigo;
    venda->valorTotal = produtos[posicao].preco * venda->quantidade;

    produtos[posicao].quantidade -= venda->quantidade;

    printf("Venda registrada com sucesso!\n");
    printf("Valor total: R$ %.2f\n", venda->valorTotal);

    return 1;
}

void listarVendas(struct Venda vendas[], int quantidade){
    if(quantidade == 0){
        printf("\nNenhuma venda registrada.\n");
        return;
    }

    for(int i = 0; i < quantidade; i++){
        printf("\n===== VENDA %d =====\n", i + 1);
        printf("Codigo do produto: %d\n", vendas[i].codigoProduto);
        printf("Quantidade vendida: %d\n", vendas[i].quantidade);
        printf("Valor total: R$ %.2f\n", vendas[i].valorTotal);
    }
}

float calcularTotalVendas(struct Venda vendas[], int quantidade){
    float total = 0;

    for(int i = 0; i < quantidade; i++){
        total += vendas[i].valorTotal;
    }

    return total;
}

int produtoMaiorReceita(struct Produto produtos[], int quantidadeProdutos, struct Venda vendas[], int quantidadeVendas){
    int posicaoMaior = -1;
    float maiorReceita = 0;

    for(int i = 0; i < quantidadeProdutos; i++){
        float receita = 0;

        for(int j = 0; j < quantidadeVendas; j++){
            if(produtos[i].codigo == vendas[j].codigoProduto){
                receita += vendas[j].valorTotal;
            }
        }

        if(receita > maiorReceita){
            maiorReceita = receita;
            posicaoMaior = i;
        }
    }

    return posicaoMaior;
}

int main(){
    struct Produto produtos[10];
    struct Venda vendas[20];

    int quantidadeProdutos = 0;
    int quantidadeVendas = 0;
    int opcao;

    do{
        printf("\n===== MENU =====\n");
        printf("1 - Cadastrar produto\n");
        printf("2 - Listar produtos\n");
        printf("3 - Registrar venda\n");
        printf("4 - Listar vendas\n");
        printf("5 - Total arrecadado\n");
        printf("6 - Produto com maior receita\n");
        printf("0 - Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        if(opcao == 1){
            if(quantidadeProdutos < 10){
                cadastrarProduto(&produtos[quantidadeProdutos]);
                quantidadeProdutos++;
            }else{
                printf("Limite de produtos atingido!\n");
            }
        }

        if(opcao == 2){
            listarProdutos(produtos, quantidadeProdutos);
        }

        if(opcao == 3){
            if(quantidadeVendas < 20){
                if(registrarVenda(produtos, quantidadeProdutos, &vendas[quantidadeVendas])){
                    quantidadeVendas++;
                }
            }else{
                printf("Limite de vendas atingido!\n");
            }
        }

        if(opcao == 4){
            listarVendas(vendas, quantidadeVendas);
        }

        if(opcao == 5){
            float total = calcularTotalVendas(vendas, quantidadeVendas);
            printf("Total arrecadado: R$ %.2f\n", total);
        }

        if(opcao == 6){
            int posicao = produtoMaiorReceita(produtos, quantidadeProdutos, vendas, quantidadeVendas);

            if(posicao == -1){
                printf("Nenhum produto possui vendas.\n");
            }else{
                printf("\n===== PRODUTO COM MAIOR RECEITA =====\n");
                printf("Produto: %s\n", produtos[posicao].nome);
                printf("Codigo: %d\n", produtos[posicao].codigo);
            }
        }

    }while(opcao != 0);

    return 0;
}

