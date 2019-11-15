#include <iostream>

using namespace std;

long long f(long long arr[], int x){

    if(arr[x] != -1)
        return arr[x];

    arr[x] = f(arr, x-1) + f(arr, x-2);
    return arr[x];
}



int main(){
    int n;

    cin >> n;

    long long *arr = new long long[n+1];
    arr[0] = 0;
    arr[1] = 1;

    for(int i = 2; i <=n; i++){
        arr[i] = -1;
    }

        cout << f(arr, n);

}
