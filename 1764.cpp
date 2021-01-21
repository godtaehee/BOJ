#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;
int main(){

    int n, m;
    cin >> n >> m;

    map<string, int> d;
    int ans = 0;
    vector<string> f;

    for(int i = 0; i < n; i++){
        string x;
        cin >> x;
        d[x]+=1;
    }

    for(int i = 0; i < m; i++){
        string x;
        cin >> x;
        if(d[x] != 0)
        {
            ans++;
            f.push_back(x);
        }
    }
    
    sort(f.begin(), f.end());

    cout << ans << '\n';
    for(string x : f)
        cout << x << '\n';

    return 0;
}
