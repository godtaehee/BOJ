#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {

    string s;
    bool judge;
    vector<char> st;

    while(1){

        judge = true;

        getline(cin, s);


        if(s == ".")
            break;

        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '(' || s[i] == '[')
                st.push_back(s[i]);
            else if(s[i] == ')'){
                if(st.empty() || st.back() != '('){
                    judge = false;
                    break;
                }else{
                    if(st.back() == '(')
                        st.pop_back();
                }
            }else if(s[i] == ']'){
                if(st.empty() || st.back() != '['){
                    judge = false;
                    break;
                }else{
                    if(st.back() == '[')
                        st.pop_back();
                }
            }else
                continue;
        }


        if(st.empty() && judge)
            cout << "yes" << endl;
        else
            cout << "no" << endl;

        st.clear();
    }

    return 0;
}
