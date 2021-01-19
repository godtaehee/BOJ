#include <iostream>
using namespace std;

int go(int p, int q){
    
    return q ? go(q, p%q) : p;
}
int main(){


    int u,v;
    int n,m;


    cin >> u >> v;
    cin >> n >> m;

    int sum = u*m + n*v;
    int under = v*m;

    int gcd = go(max(sum,under),min(sum,under));

    cout << sum / gcd << ' ' << under / gcd << '\n';


    return 0;
}
