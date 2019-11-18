#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

    int x,y,w,h;

    int x1,y1;

    vector<int> s;

    cin >> x >> y >> w >> h;

    x1 = w - x;
    y1 = h - y;

    s.push_back(x);
    s.push_back(y);
    s.push_back(x1);
    s.push_back(y1);

    sort(s.rbegin(), s.rend());

    cout << s.back() << endl;




    return 0;
}
