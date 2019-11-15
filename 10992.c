#include <stdio.h>

int main(){
	
	int a;
	
	scanf("%d", &a);
	
	for(int i = 0; i < a - 1; i++){
		
		for(int j = 0; j < a - i - 1; j++){
			printf(" ");
		}
		
		
		if(i != 0)
			printf("*");
		
		
		for(int x = 0; x < 2 * i - 1; x++){
			printf(" ");
		}
		
		printf("*\n");
		
		

	}
	
		for(int x = 0; x < 2 * a - 1; x++){
			printf("*");	
		}
		
	printf("\n");


	
	return 0;
}
