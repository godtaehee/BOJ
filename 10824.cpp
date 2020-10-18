#include <iostream>
#include <cmath>
using namespace std;
typedef long long int ll;
int main(){

    ll a,b,c,d;
    cin >> a >> b >> c >> d;

    // B와 D의 자릿수 만큼의 10의 거듭제곱이 각각 A와 C에 곱해져야 A와B, C와D를 붙힐수있다.
    ll save_b = (ll)b;
    ll save_d = (ll)d;


    int count_b = 0; // B의 자리수

    do{
        b/=10ll;
        count_b++;
    }while(b>0);

    int count_d = 0; // D의 자리수

    do{
        d/=10ll;
        count_d++;
    }while(d>0);


    cout << (ll)((ll)a*(ll)(pow(10,count_b)) + (ll)save_b) // A와 B 붙힌값
    + (ll)((ll)c*(ll)(pow(10,count_d)) + (ll)save_d)<< '\n'; // C와 D 붙힌값

    return 0;
}
