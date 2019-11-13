#include <stdio.h>

int main(){
	
	int a;
	
	scanf("%d", &a);
	
	for(int i = 0; i < a; i++){
		for(int j = 0; j < a - i - 1; j++){
			printf(" ");
		}
		
		for(int z = 0; z <= i; z++){
			printf("*");
		}
		printf("\n");
		
	}
	
	for(int i = 0; i < a; i++){
		for(int j = 0; j <= i; j++){
			printf(" ");
		}
		
		for(int z = 0; z < a - i - 1; z++){
			printf("*");
		}
		printf("\n");
		
	}
	
	
}
