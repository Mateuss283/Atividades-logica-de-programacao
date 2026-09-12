#include <stdio.h>
#include <string.h>

int main(){
	
	char nome[20];
	char sexo[20];
	char estado_civil[20];
	int tempo_casamento;
	
	printf("Escreva seu nome: ");
	scanf("%s", nome);
	
	printf("Escreva seu sexo em F ou M: ");
	scanf("%s", sexo);
	
	printf("Escreva seu estado civil: ");
	scanf("%s", estado_civil);
	
	if (strcmp(sexo, "F") == 0 && strcmp(estado_civil, "Casada") == 0) {
		printf("Qual o tempo de casamento em anos? ");
		scanf("%d", &tempo_casamento);
	}
	
	return 0;	
}
