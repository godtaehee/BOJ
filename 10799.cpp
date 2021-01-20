#include <iostream>
#include <vector>

using namespace std;
int main(){

    string s;
    int ans = 0;
    cin >> s;
    int size = s.size();

    vector<int> f;

    for(int i = 0; i < size; i++){
        if(s[i] == '(')
            f.push_back(i);
        else{
            if(!f.empty()) {
                if (f.back() == i - 1) {
                    f.pop_back();
                    ans += f.size();
                }else{
                    ans+=1;
                    f.pop_back();
                }
            }
        }
    }
    cout << ans << '\n';
    return 0;
}
