#include <iostream>

using namespace std;

int main(){

    int h, m;

    scanf("%d %d", &h, &m);

    if(m < 45){
        m = 15 + m;
        h--;
    } else
        m = m - 45;

    if(h == - 1)
        h = 23;

    cout << h << ' ' << m;

    return 0;
}
