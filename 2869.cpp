#include <iostream>

using namespace std;

int main(){

    long long A, B, V;

    cin >> A >> B >> V;


    if((V-A) % (A-B) == 0)
        cout << (V - A) / (A - B) + 1 << endl;
    else
        cout << (V - A) / (A - B) + 2 << endl;

    return 0;
}
