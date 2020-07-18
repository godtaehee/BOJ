#include <iostream>
#include <tuple>
#include <queue>
#include <cstring>
using namespace std;

// 화면에 이모티콘의 개수가 s개일때 클립보드에 저장된 이모티콘의 개수 c
// 클립보드에 저장된 이모티콘의 개수가 1개일때 화면의 개수 s
// 클립보드에 저장된 이모티콘의 개수가 2개일때 화면의 개수 s ''' 이렇게해
// 클립보드에 저장된 이모티콘의 개수가 n개일때 화면의 개수 s
// 중에서 최소값을 찾는문제

int main(){
    int d[1001][1001];
    int n;
    memset(d, -1, sizeof(d));
    queue<pair<int,int>> q;
    d[1][0] = 0;
    q.push(make_pair(1,0));
    cin >> n;
    while(!q.empty()){
        int s,c;
        tie(s,c) = q.front();
        q.pop();
        // d[s][s] 는 d[s][c]에서 1초 더걸린다 d[s][c]의 영향을 d[s][s]가 받는다
        if(d[s][s] == -1){
            d[s][s] = d[s][c] + 1;
            q.push(make_pair(s,s));
        }
        if(s+c <= n && d[s+c][c] == -1){
            d[s+c][c] = d[s][c] + 1;
            q.push(make_pair(s+c,c));
        }
        if(s-1 >= 0 && d[s-1][c] == -1){
            d[s-1][c] = d[s][c] + 1;
            q.push(make_pair(s-1,c));
        }
    }

    int ans = -1;
    for(int i = 0; i <= n; i++){
        if(d[n][i] != -1){
            if(ans == -1 || ans > d[n][i]){
                ans = d[n][i];
            }
        }
    }

    cout << ans << '\n';
    return 0;
}
