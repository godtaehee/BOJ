#include <iostream>
#include <cstring>

using namespace std;
int main(){

    int n, m;
    int f[101][101];
    cin >> n >> m;
    memset(f, 0, sizeof(f));
    while(n--){
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        for(int i = x1; i <= x2; i++){
            for(int j = y1; j <= y2; j++){
                f[i][j]+=1;
            }
        }
    }

    int answer = 0;
    for(int i = 1; i < 101; i++){
        for(int j = 1; j < 101; j++){
            if(f[i][j] <= m)
                answer++;
        }
    }
    cout << 10000 - answer << '\n';
    return 0;
}
