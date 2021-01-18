#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> p;
vector<int> a;
vector<int> aIdx;
bool cmd(int u, int v){
    if (a[u] == a[v]){
        return u < v;
    }
    return a[u] <= a[v];
}

int main(){

    int n;

    cin >> n;

    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        a.push_back(x);
        aIdx.push_back(i);
        p.push_back(0);
    }

    sort(aIdx.begin(), aIdx.end(), cmd);

    for(int i = 0; i < n; i++){
        p[aIdx[i]] = i;
    }


    for(int i = 0; i < n; i++){
        if(i!=n-1)
            cout << p[i] << ' ';
        else
            cout << p[i];

    }

    return 0;
}
