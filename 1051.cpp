#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

bool judge(int a, int b, int c, int d){
    if(a == b && b==c && c == d && d == a)
        return true;
    return false;
}
int main(){
    
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    
    int n, m;
    cin >> n >> m;
    int maxSize = min(n,m);

    int f[51][51];
    memset(f, 0, sizeof(f));

    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        for(int j = 0; j < m; j++){
            f[i][j] = s[j] - '0';
        }
    }

    int ans = 1;

    for(int i = 2; i <= maxSize; i++){
       for(int j = 0; j <= n-i; j++){
           for(int k = 0; k <= m-i; k++){
               if(judge(f[j][k], f[j+i-1][k+i-1], f[j+i-1][k], f[j][k+i-1])){
                   ans = i;
               }
           }
       }
    }

    cout << ans * ans << '\n';

    return 0;
}
