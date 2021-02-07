#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int n;
    cin >> n;
    map<string,int> m;
    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        m[s]++;
    }

    int max = -1;
    string best = "";
    map<string,int>::iterator it;
    vector<string> f;

    for(it = m.begin(); it!=m.end(); it++){
        if(m[it->first] > max){
            if(!f.empty())
                f.clear();
            max = m[it->first];
            f.push_back(it->first);
        }
    }
    sort(f.begin(),f.end());
    cout << f[0] << '\n';
    return 0;
}
