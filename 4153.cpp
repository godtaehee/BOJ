#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

    long long x, y, z;

    vector<long long> s;

    while(1){
        
        cin >> x >> y >> z;
        
        if(x == 0 && y == 0 && z == 0)
            break;

        s.push_back(x);
        s.push_back(y);
        s.push_back(z);

        sort(s.begin(), s.end());


        if(pow(s.at(2),2) == pow(s.at(0),2) + pow(s.at(1),2))
            cout << "right" << endl;
        else
            cout << "wrong" << endl;
        
        s.clear();
    }



    return 0;
}
