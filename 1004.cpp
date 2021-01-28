#include <iostream>
#include <tuple>
#include <vector>
#include <cmath>

using namespace std;
int main(){

    int t;

    cin >> t;
    while(t--){
        int x1, y1, x2, y2;
        int ans = 0;
        cin >> x1 >> y1 >> x2 >> y2;
        vector<tuple<int,int,int>> f;
        int circleCnt;
        cin >> circleCnt;
        for(int i = 0; i < circleCnt; i++){
            int x, y, r;
            cin >> x >> y >> r;
            f.push_back(make_tuple(x,y,r));
        }
        for(int i = 0; i < circleCnt; i++){
            int x1Dist = get<0>(f[i]) - x1;
            int y1Dist = get<1>(f[i]) - y1;
            int x2Dist = get<0>(f[i]) - x2;
            int y2Dist = get<1>(f[i]) - y2;
            if(pow(x1Dist,2) + pow(y1Dist,2) < pow(get<2>(f[i]),2) && pow(x2Dist,2) + pow(y2Dist,2) > pow(get<2>(f[i]),2)) ans++;
            if(pow(x1Dist,2) + pow(y1Dist,2) > pow(get<2>(f[i]),2) && pow(x2Dist,2) + pow(y2Dist,2) < pow(get<2>(f[i]),2)) ans++;
        }
        cout << ans << '\n';
    }

    return 0;
}
