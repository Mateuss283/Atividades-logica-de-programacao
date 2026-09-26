#include <stdio.h>

int main(){

    int numero;
    int maior;

    for(int contador = 1; contador <= 10; contador++){
        printf("Digite o numero %d: ", contador);
        scanf("%d", &numero);

        if(contador == 1){
            maior = numero;
        }else if(numero > maior){
            maior = numero;
        }
    }

    printf("\nO maior numero e: %d", maior);

    return 0;
}
