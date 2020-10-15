#include <iostream>
using namespace std;
typedef long long int ll;
int main(){


    ll a, b;
    cin >> a >> b;

    if((ll)a > (ll)b){
        ll tmp = (ll)a;
        a = (ll)b;
        b = (ll)tmp;

    }else if((ll)a==(ll)b){
        cout <<'0' << '\n';

        return 0;
    }
    cout <<(ll)(b-a-1) << '\n';

    for(ll i = (ll)(a+1); i < (ll)b; (ll)i++){
        cout << i << ' ';
    }

    return 0;
}
