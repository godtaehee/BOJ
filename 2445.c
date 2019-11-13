#include <stdio.h>

int main(){
	
	int a;
	
	scanf("%d", &a);
	
	for(int i = 0; i < a; i++){
		for(int j = 0; j < i + 1; j++){
			printf("*");
		}
		
		for(int z = 1; z < 2 * (a - i) - 1 ; z++){
			printf(" ");
		}
		
		for(int x = 0; x <= i; x++){
			printf("*");
		}
		
		printf("\n");
	}
	
	for(int i = 0; i < a; i++){
		for(int j = 0; j < a - i - 1; j++){
			printf("*");
		}
		
		for(int z = 0; z < 2 * ( i+1 ); z++){
			printf(" ");
		}
		
		for(int j = 0; j < a - i - 1; j++){
			printf("*");
		}
		
		printf("\n");
	}
	
	
}
