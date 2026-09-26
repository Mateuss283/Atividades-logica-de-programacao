#include <stdio.h>

int main(){
	
	int alunos;
	float nota;
	float soma = 0;
	float media;
	
	printf("Quantos alunos ha na turma? ");
	scanf("%d", &alunos);
	printf("\n");
	
	for(int contador = 1; contador <= alunos; contador++){
		printf("Digite a nota do %d aluno: ", contador);
		scanf("%f", &nota);
		soma = soma + nota;
	}
	
	media =  soma / alunos;
	printf("\nA media da turma e: %.2f", media);
}
