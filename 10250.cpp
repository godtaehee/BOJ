#include <iostream>

using namespace std;

int main(){

    int T;
    int H, W, N;

    cin >> T;

    while(T--){
        cin >> H >> W >> N;

        if(H * W < N)
            return 0;
        if(W>99)
            return 0;

        W = N / H + 1;

        if(N % H != 0){
            H = N % H;
        } else
            W = N/H;



        cout << H * 100 + W << endl;
    }

    return 0;
}
