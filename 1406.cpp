#include <iostream>
#include <stack>

using namespace std;
int main(){

    stack<char> left;
    stack<char> right;

    string sentence;
    cin >> sentence;
    for(char x : sentence){
        left.push(x);
    }

    int t;
    cin >> t;
    while(t--){
        char cmd;
        cin >> cmd;
        char x;
        if(cmd=='L'){
            if(!left.empty()){
                x = left.top();
                left.pop();
                right.push(x);
            }
        }else if(cmd=='D'){
            if(!right.empty()){
                x = right.top();
                right.pop();
                left.push(x);
            }
        }else if(cmd=='B'){
            if(!left.empty()){
                left.pop();
            }
        }else if(cmd=='P'){
            cin >> x;
            left.push(x);
        }
    }

    while(!left.empty()){
        char tmp = left.top();
        right.push(tmp);
    }

    while(!right.empty()){
        cout << right.top();
        right.pop();
    }

    cout << '\n';
    return 0;
}
