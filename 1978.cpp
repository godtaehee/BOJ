#include <iostream>

using namespace std;

bool judge(int x){

    if(x == 1)
        return false;

    bool t = true;

    for(int i = 2; i < x; i++){
        if(x % i == 0)
            t = false;
    }

    if(t == true)
        return true;
    else
        return false;
}


int main(){

    int n;
    int count = 0;
    int x;

    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> x;
        if(judge(x) == true)
            count++;
    }

    cout << count;



    return 0;
}
