#include <iostream>
#include <cmath>

using namespace std;


int judge(int x) {
    
    if(x == 1)
        return 1;
    
    int c = 1;
    int p;
    int q;

    while(1){
        p =  3*c * (c -1) +1;
        q = 3 * c *(c+1) +1;
        c++;
        if(x >= p && x <= q){
            break;
        }
    }

    return c;
}

int main(){

    int n;

    cin >> n;

    cout << judge(n);
    return 0;
}
