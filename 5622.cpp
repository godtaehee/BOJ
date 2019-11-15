#include <iostream>

using namespace std;

int main(){

    string x;
    int sum = 0;
    int tmp[26] = {3,3,3,4,4,4,5,5,5,6,6,6,7,7,7,8,8,8,8,9,9,9,10,10,10,10};

    cin >> x;

    for(int i = 0; i < x.length(); i++){
        sum+= tmp[(int)x[i] % 65];
    }

    cout << sum;
    
    return 0;
}
