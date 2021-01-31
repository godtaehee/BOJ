#include <iostream>
#include <vector>


using namespace std;

int ans = 0;
int n, s;
vector<int> f;
void go(int sum, int digit){
    if(sum == s && digit!=0){
        ans++;
    }
    if(digit == n) return;
    for(int i = digit; i < n; i++){
        go(sum+f[i],i+1);
    }
}
int main(){


    cin >> n >> s;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        f.push_back(x);
    }

    go(0,0);

    cout << ans << '\n';
    return 0;
}
