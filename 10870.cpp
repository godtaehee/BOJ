#include <iostream>

using namespace std;

int main(){

    int fibo[21] = {0,};
    fibo[1] = 1;

    for(int i = 2; i < 21; i++)
        fibo[i]+=(fibo[i-1]+fibo[i-2]);

    int N;

    cin >> N;

    cout << fibo[N];


    return 0;
}
