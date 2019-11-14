#include <iostream>

using namespace std;

void print(int a, int b){
	
	int chleo, chlth;
	
	if(a>b){
		for(int i = 1; i<b+1; i++)
			if(a%i == 0 && b%i == 0)
				chleo = i;
			

	}
	else{
		for(int i = 1; i<a+1; i++)
			if(a%i == 0 && b%i == 0){
				chleo = i;
			}

	}
	

	if(a>b){
		for(int j = b; j<a*b+1; j++){
			if(j % a == 0 && j % b ==0){
				chlth = j;
				break;
			}

		}
	}
	else{
		for(int j = a; j<a*b+1; j++){
			if(j % a == 0 && j % b == 0){
				chlth = j;
				break;
			}

	}
}

	cout << chleo << endl << chlth; 

	
}


int main(){
	
	int a, b;
	
	cin >> a >> b;
	print(a,b);

	return 0;
}
