#include <iostream>

using namespace std;

int main(){

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N;
    int X;


    cin >> N >> X;

    int a[N];

    for(int i = 0; i < N; i++)
        cin >> a[i];

    for(int i = 0; i < N; i++){
        if(a[i] < X)
            cout << a[i] << ' ';
    }



}
