#include <iostream>
#include <algorithm>
using namespace std;
int main(){

    int n, m;
    cin >> n >> m;

    string s = "";

    do{
        if(n%m > 9)
            s+=(char)(n%m+55);
        else
            s+=(char)((n%m) + '0');
        n/=m;

    }while(n>0);

    reverse(s.begin(),s.end());
    cout << s << '\n';

    return 0;
}
