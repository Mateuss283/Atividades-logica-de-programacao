#include <stdio.h>

int main(){
	
	int contador = 10;
	
	while(contador >= 0){
		printf("%d\n", contador);
		contador--;
		Sleep(10);
	}
	printf("Fim da contagem.");
}
