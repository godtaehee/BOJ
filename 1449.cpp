#include <iostream>
#include <cstring>

using namespace std;

int main(){

    int n, m;
    cin >> n >> m;
    m*=10;

    bool f[10001];
    memset(f,0,sizeof(f));
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        x*=10;
        for (int j = x-5; j < x + 6; j++) {
            f[j] = true;
        }
    }

    int cnt = 0;
    int idx= 0;
    while(1){
        idx++;
        if(idx >= 10001) break;
        if(f[idx]){
            cnt+=1;
            idx+=m;
        }
    }

    cout << cnt << '\n';

    return 0;
}
