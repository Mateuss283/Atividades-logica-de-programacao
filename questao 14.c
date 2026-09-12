#include <stdio.h>

int main (){
	
	int ano_nascimento;
	int ano_atual;
	int idade;
	int idade_2050;
	
	
	printf("Em que ano voce nasceu? ");
	scanf("%d", &ano_nascimento);
	
	printf("Em que ano estamos? ");
	scanf("%d", &ano_atual);
	
	idade = ano_atual - ano_nascimento;
	idade_2050 = 2050 - ano_nascimento;
	
	printf("\nVoce tem %d anos e tera %d em 2025.", idade, idade_2050);
	
	return 0;

}
