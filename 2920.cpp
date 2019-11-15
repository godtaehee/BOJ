#include <iostream>
#include <cstring>

using namespace std;

int main(){

    char arr[9];
    for(int i = 0; i < 8; i++){
        cin >> arr[i];
    }
    
    if(strcmp(arr,"12345678") == 0)
        cout << "ascending";
    else if(strcmp(arr,"87654321") == 0)
        cout << "descending";
    else
        cout << "mixed";

    return 0;
}
