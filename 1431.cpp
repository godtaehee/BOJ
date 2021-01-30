#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmd(string a, string b){

    int aSize = a.size();
    int bSize = b.size();
    int aSum = 0;
    int bSum = 0;
    if(aSize != bSize){
        return aSize < bSize;
    }else{
        for(int i = 0; i < aSize; i++){
            if(a[i] >= 48 && a[i] <= 57)
                aSum += a[i] - '0';
            if(b[i] >= 48 && b[i] <= 57)
                bSum += b[i] - '0';
        }
        return aSum == bSum ? a < b : aSum < bSum;
    }
}
int main(){

    int n;
    cin >> n;

    vector<string> f;
    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        f.push_back(s);
    }

    sort(f.begin(), f.end(), cmd);

    for(auto x : f)
        cout << x << '\n';


    return 0;
}
