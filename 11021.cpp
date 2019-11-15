#include <iostream>

using namespace std;

int main(){
	
	int T;
	int B;
	int a, b;
	cin >> T;
	
	B = T; 
	
	while(T--){
		
		scanf("%d %d", &a, &b);
		printf("Case #%d: %d\n", B-T ,a + b);  
	}
	
	return 0;
}
