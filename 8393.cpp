#include <iostream>

using namespace std;

int main(){
	
	int a;
	int sum = 0;
	
	scanf("%d", &a);
	
	while(a != 0){
		sum += a;
		a--;
	}
		
		
	printf("%d\n", sum);
		 
	
	return 0;
}
