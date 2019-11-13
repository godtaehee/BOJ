#include <stdio.h>

int main(){
	
	int a;
	
	scanf("%d", &a);
	
	for(int i = 0; i < a; i++){
		
		for(int j = 0; j < i; j++){
			printf(" ");
		}
		
		for(int j = 0; j < 2 * (a - i) - 1; j++){
			printf("*");
		}
		
		
		printf("\n");
	}
	
	for(int i = 0; i < a - 1; i++){
		
		for(int j = 1; j < a - i - 1; j++){
			printf(" ");
		}
		
		for(int z = 0; z < 2 * i + 3; z++){
			printf("*");
		}
		
		
		printf("\n");
	}
	
	
}
