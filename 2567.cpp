#include <iostream>
#include <cstring>

using namespace std;
int dx[4] ={0,0,1,-1};
int dy[4] ={1,-1,0,0};
int main(){

    int n;
    cin >> n;
    int f[101][101];
    memset(f,0,sizeof(f));
    int ans = 0;

    while(n--){
        int u, v;
        cin >> u >> v;
        for(int i = u; i < u+10; i++){
            for(int j = v; j < v+10; j++){
                    f[i][j] = 1;
            }
        }
    }
    for(int i = 0; i < 101; i++){
        for(int j = 0; j < 101; j++){
            if(f[i][j] == 0) continue;
            for(int k = 0; k < 4; k++){
                int nx = i+dx[k];
                int ny = j+dy[k];
                if(nx>= 0 && nx < 101 && ny >= 0 && ny < 101){
                    if(f[nx][ny] == 0) ans++;
                }
            }
        }
    }
    
    cout << ans << '\n';
    return 0;
}
