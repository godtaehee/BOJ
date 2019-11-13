#include <iostream>
#include <stdio.h>

using namespace std;

int main(){

    int T;
    int n = 0;

    int za[41] = {0,}; // f(zero) Array
    int oa[41] = {0,}; // f(one) Array

    za[0] = 1;
    oa[1] = 1;



    for(int i = 2; i <= 40; i++){
        za[i]+=(za[i-1] + za[i-2]);
        oa[i]+=(oa[i-1] + oa[i-2]);
    }

    scanf("%d", &T);

    for(int i = 0; i < T; i++){
        scanf("%d", &n);

        cout << za[n] << ' ' << oa[n] << endl;
    }
    return 0;
}
