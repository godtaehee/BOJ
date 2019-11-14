#include <iostream>

using namespace std;

bool judege(int x){

    if(x == 1)
        return false;

    for(int i = 2; i <x; i++){
        if(x % i == 0)
            return false;
    }

    return true;
}




int sum(int arr[], int M, int N){

    int count = 0;

    for(int i = M; i <=N; i++){
        if(judege(i) == true)
            arr[count++] = i;
    }

    return count;

}









int main(){

    int M, N;

    cin >> M >> N;

    int arr[6000] = {-1};
    int Csum = 0;

    int size = sum(arr, M, N);

    for(int i = 0; i < size; i++){
        Csum += arr[i];
    }
    if(arr[0] == -1)
        cout << "-1";
    else
    cout << Csum << endl << arr[0];


    return 0;

}
