#include <iostream>

using namespace std;

int main(){

    long long A, B, C;

    cin >> A >> B >> C;



        if(C-B <= 0)
            cout << "-1" << endl;
        else
            cout << A / (C - B) + 1;

    return 0;
}
