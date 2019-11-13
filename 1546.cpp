#include <iostream>

using namespace std;

int main(){

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    double max, sum =0;
    int N;

    cin >> N;

    int a[N];

    for(int i = 0; i < N; i++)
        cin >> a[i];

    max = a[0];

    for(int i = 0; i < N; i++){
        if(a[i] > max)
            max = a[i];
    }

    for(int i = 0; i < N; i++)
        sum += (a[i] / max) * 100;
    
    cout << sum / N;

}
