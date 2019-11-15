#include <iostream>
#include <cstring>
using namespace std;

int main(){
	
	int arr[26];
	int index = 0;
	char *word = new char[100];
	
	cin >> word;
	
	int length = strlen(word);
	
	for(int i = 0; i < 26; i++){
		arr[i] = -1;
	}	
	
	for(int i = 0; i < length; i++){
		
		index = (int)word[i] % 97;
			if(arr[index] == -1)
				arr[index] = i;
	}
	
	for(int i = 0; i <26; i++)
		cout << arr[i] << ' ';
	
	return 0;
}
