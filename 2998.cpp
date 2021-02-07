#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>

using namespace std;

string change(string x){
    int tmp = 0;
    for(int i = 0; i < 3; i++){
        tmp += (x[i]-'0')*pow(2,i);
    }
    return to_string(tmp);
}
int main(){
    string s;
    cin >> s;
    string ans = "";
    int size = s.size();
    reverse(s.begin(),s.end());
    if(size%3!= 0){
        for(int i = 0; i < 3-size%3; i++){
            s+="0";
        }
    }

    for(int i = 0; i < s.size(); i+=3){
        ans += change(s.substr(i,3));
    }
    reverse(ans.begin(),ans.end());
    cout << ans << '\n';
    return 0;
}
