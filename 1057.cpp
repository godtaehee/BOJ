#include <iostream>
using namespace std;
int main(){

    int n, p, q;
    int ans = 0;
    cin >> n >> p >> q;
    if(n < p || n < q)
        cout << "-1" << '\n';
    else{
        while(p!=q){
            p = (p+1)/2;
            q = (q+1)/2;
            ans++;
        }
    }
    cout << ans << '\n';
}
