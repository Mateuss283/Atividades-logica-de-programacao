#include <stdio.h>

int main(){
	
	int aprovado = 0;
	int reprovado = 0;
	float nota;
	float percentual;
	
	for(int contador =1; contador <= 10; contador++){
		printf("Digite a nota do aluno %d: ", contador);
		scanf("%f", &nota);
		if(nota >= 7){
			aprovado++;
			printf("--- Aluno %d aprovado ---\n\n", contador);
		}else{
			reprovado++;
			printf("--- Aluno %d reprovado ---\n\n", contador);
		}
	}
	
	 percentual = (aprovado / 10.0) * 100;

    printf("\nQuantidade de aprovados: %d", aprovado);
    printf("\nQuantidade de reprovados: %d", reprovado);
    printf("\nPercentual de aprovacao: %.2f%%\n", percentual);
    
    return 0;
}
