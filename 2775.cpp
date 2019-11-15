#include <iostream>

using namespace std;

int suming(int arr[15][15], int k, int n){

    int sum = 0;
    for(int i = 1; i <= n; i++)
        sum+=arr[k-1][i];

    return sum;
}

int main(){

    int arr[15][15];

    for(int i = 1; i < 15; i++){
        arr[0][i] = i;
    }


    for(int i = 1; i < 15; i++){
        for(int j = 1; j < 15; j++){
            arr[i][j] = suming(arr, i, j);
        }
    }

    int T, k, n;

    cin >> T;
    while(T--){
        cin >> k >> n;
        cout << arr[k][n] << endl;
    }

    return 0;
}
