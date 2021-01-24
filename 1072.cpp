#include <iostream>
using namespace std;
int main(){

    long long x, y;
    cin >> x >> y;
    long long z = (100*y)/x + 1;
    if(z == 100 || z == 101){
        cout << "-1" << '\n';
        return 0;
    }

    long long ans = -1;

    int start = 1, end = 1000000000;
    while(start <= end){
        int mid = (start+end)/2;
        long long newZ = ((y+mid)*100)/(x+mid);
        if(newZ >= z) {
            end = mid-1, ans = mid;
        }
        else start = mid+1;

    }

    cout << ans << '\n';



    return 0;
}
