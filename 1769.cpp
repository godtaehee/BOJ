#include <iostream>
#include <cstring>

using namespace std;
int main(){

    string s;
    getline(cin,s);
    int f[10];


    if(s.size() == 1){
        if((s[0]-'0')%3 == 0){
            cout << "0\nYES\n";
        }else{
            cout << "0\nNO\n";
        }
        return 0;
    }
    int cnt = 0;
    while(1){
        int sum = 0;
        memset(f,0,sizeof(f));
        for(int i = 0; i < s.size(); i++){
            f[s[i]-'0']++;
        }
        for(int i = 0; i < 10; i++){
            sum+=f[i]*i;
        }
        if(sum/10 == 0){
            cout << cnt+1 << '\n';
            if(sum%3 == 0)
                cout << "YES" << '\n';
            else
                cout << "NO" << '\n';
            break;
        }else{
            s = to_string(sum);
            cnt++;
        }
    }
    return 0;
}
