#include <stdio.h>

int main(){

    int num1, num2, num3;

    printf("Digite tres numeros: ");
    scanf("%d %d %d", &num1, &num2, &num3);

    if(num1 > num2 && num1 > num3){

        if(num2 > num3){
            printf("\nOs numeros em ordem crescente e: %d %d %d", num1, num2, num3);
        }else{
            printf("\nOs numeros em ordem crescente e: %d %d %d", num1, num3, num2);
        }

    }else if(num2 > num1 && num2 > num3){

        if(num1 > num3){
            printf("\nOs numeros em ordem crescente e: %d %d %d", num2, num1, num3);
        }else{
            printf("\nOs numeros em ordem crescente e: %d %d %d", num2, num3, num1);
        }

    }else{

        if(num1 > num2){
            printf("\nOs numeros em ordem crescente e: %d %d %d", num3, num1, num2);
        }else{
            printf("\nOs numeros em ordem crescente e: %d %d %d", num3, num2, num1);
        }

    }

    return 0;
}
