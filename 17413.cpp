#include <iostream>
#include <queue>
#include <vector>


using namespace std;
int main(){
    string s;

    getline(cin, s);
    int size = s.size();
    queue<char> ans;
    vector<char> v;

    int i = 0;

    while(1){
        if(i == size) break;
        if(s[i] == ' '){
            while(!v.empty()){
                ans.push(v.back());
                v.pop_back();
            }
            ans.push(s[i]);
        }else if(s[i] == '<'){
            if(!v.empty()){
                while(!v.empty()){
                    ans.push(v.back());
                    v.pop_back();
                }
            }
            while(s[i]!='>'){
                ans.push(s[i]);
                i++;
            }
            ans.push(s[i]);
        }else{
            v.push_back(s[i]);
        }
        i++;
    }

    if(!v.empty()){
        while(!v.empty()){
            ans.push(v.back());
            v.pop_back();
        }
    }

    while(!ans.empty()){
        cout << ans.front();
        ans.pop();
    }

    return 0;
}
