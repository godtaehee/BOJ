#include <iostream>
#include <vector>

using namespace std;

int main(){

    int T;
    int x;
    int sum = 0;
    vector<int> s;

    cin >> T;

    for(int i = 0; i < T; i++){
        cin >> x;

        if(x){
            s.push_back(x);
        }
        else
            s.pop_back();
    }

    for(auto a : s){
        sum+=a;
    }

    cout << sum;

    return 0;
}
