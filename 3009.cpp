#include <iostream>
#include <set>

using namespace std;

int main(){

    multiset<int> x;
    multiset<int> y;
    multiset<int>::iterator ix;
    multiset<int>::iterator iy;
    int cox;
    int coy;
    bool change = true;

    for(int i = 0; i < 3; i++){
            cin >> cox >> coy;
            x.insert(cox);
            y.insert(coy);
    }

    if(x.count(cox) == 2){
        x.erase(cox);
        x.erase(cox);
        ix = x.begin();
        cout << *ix << ' ';
    }
    else{
        cout << cox << ' ';
    }

    if(y.count(coy) == 2){
        y.erase(coy);
        y.erase(coy);
        iy = y.begin();
        cout << *iy;
    }
    else{
        cout << coy;
    }

    return 0;
}
