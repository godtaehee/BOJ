#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int main(){

    string s;
    cin >> s;
    vector<string> ans;
    int size = s.size();
    int count = 1;
    for(int i = 1; i < size; i++){
        string tmp1 = s.substr(0,i);
        string tmp2 = s.substr(i);
        for(int j = 1; j < tmp2.size(); j++){
            tmp1 = s.substr(0,i);
            string tmp3 = tmp2.substr(0,j);
            string tmp4 = tmp2.substr(j);
            reverse(tmp1.begin(), tmp1.end());
            reverse(tmp3.begin(), tmp3.end());
            reverse(tmp4.begin(), tmp4.end());

            tmp1 = tmp1 + tmp3 + tmp4;
            ans.push_back(tmp1);
        }
    }

    sort(ans.begin(),ans.end());
    cout << ans[0] << '\n';
    return 0;
}
