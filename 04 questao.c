#include <stdio.h>

int main (){
	
	int A;
	int B;
	int C;
	
	printf("Digite o valor de A: ");
	scanf("%d", &A);
	
	printf("Digite o valor de B: ");
	scanf("%d", &B);
	
	
	if(A == B) {
		C = A +  B;
	}else{
		C = A * B;
	}
	
	printf("\nO valor de C e: %d", C);
	
	return 0;
	
}
