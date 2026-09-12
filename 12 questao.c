#include <stdio.h>

int main(){
	
	int IDaluno;
	float nota1, nota2, nota3;
	float media;
	float MA;
	char conceito;
	
	
	printf("Digite o seu numero de identificacao de aluno: ");
	scanf("%d", &IDaluno);
	
	printf("Digite a primeira nota: ");
	scanf("%f", &nota1);
	
	printf("Digite a segunda nota: ");
	scanf("%f", &nota2);
	
	printf("Digite a terceira nota: ");
	scanf("%f", &nota3);
	
	printf("Digite a media dos exercicios: ");
	scanf("%f", &media);
	
	MA = (nota1 + nota2 * 2 + nota3 * 3 + media) / 7;
	
	if(MA >= 90){
		conceito = 'A';
	}else if(MA >= 75){
		conceito = 'B';
	}else if(MA >= 60){
		conceito = 'C';
	}else if(MA >= 40){
		conceito  =  'D';
	}else{
		conceito = 'E';
	}
	
	if(conceito == 'A' || conceito == 'B' || conceito == 'C'){
		printf("\nVoce foi aprovado!");
	}else
		printf("\nVoce foi reprovado!");
	
	printf("\nSeu numero de identificacao: %d", IDaluno);
	printf("\nSuas notas respectivamente: %.2f, %.2f, %.2f", nota1, nota2, nota3);
	printf("\nSua media dos exercicios: %.2f", media);
	printf("\nSua media de aproveitamento: %.2f", MA);
	printf("\nSeu conceito obtido: %c", conceito);
	
	return 0;
	
}
