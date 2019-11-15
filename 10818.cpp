#include <iostream>

using namespace std;

int main(){
	
	
	int a;
	int Min;
	int Max;
	
	
	scanf("%d", &a);
	
	int *b = new int[a-1];
	
	for(int i = 0; i < a; i++)
		scanf("%d", &b[i]);
	
	
	Min = b[0];
	
	for(int i = 1; i < a; i++){
		if(Min > b[i])
			Min = b[i];
	}
	
	Max = b[0];
	
	for(int j = 1; j < a; j++){
		if(Max < b[j])
			Max = b[j];
	}
	
	printf("%d %d\n", Min, Max);

	
	return 0;
}
