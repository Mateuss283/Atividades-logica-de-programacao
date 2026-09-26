#include <stdio.h>

int main(){

    int opcao;
    float saldo = 1000;
    float valor;

    do{
        printf("--- CAIXA ELETRONICO ---\n");
        printf("1. Consultar saldo\n");
        printf("2. Depositar\n");
        printf("3. Sacar\n");
        printf("4. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        if(opcao == 1){

            printf("\nSaldo: R$ %.2f\n", saldo);

        }else if(opcao == 2){

            printf("\nDigite o valor do deposito: R$ ");
            scanf("%f", &valor);

            saldo = saldo + valor;

            printf("Deposito realizado!\n");

        }else if(opcao == 3){

            printf("\nDigite o valor do saque: R$ ");
            scanf("%f", &valor);

            if(valor <= saldo){
                saldo = saldo - valor;
                printf("Saque realizado!\n");
            }else{
                printf("Saldo insuficiente!\n");
            }

        }else if(opcao == 4){

            printf("\nSaindo...\n");

        }else{

            printf("\nOpcao invalida!\n");
        }

    }while(opcao != 4);

    return 0;
}
