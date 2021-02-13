#include <iostream>
#include <deque>
#include <cstring>
using namespace std;
int main(){

    int n;
    deque<int> dq;
    cin >> n;
    for(int i = 0; i < n; i++){
        dq.push_back(i);
    }

    int ans[1001];
    memset(ans,0,sizeof(ans));
    int cnt = 1;
    while(!dq.empty()){
        for(int i = 0; i < cnt; i++){
            int tmp = dq.front();
            dq.pop_front();
            dq.push_back(tmp);
        }
        ans[dq.front()] = cnt++;
        dq.pop_front();
    }

    for(int i = 0; i < n; i++){
        cout << ans[i] << ' ';
    }
    cout << '\n';




    return 0;
}
