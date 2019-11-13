#include <iostream>

using namespace std;

int judge(int arr[], int M, int N){

    int count = 0;

    for(int i = M; i<=N; i++){

        for(int j = 1; j <= 100; j++){
            if(j*j == i){
                arr[count++] = i;
                break;
            }

        }
    }

    return count;
}


int main(){

    int M,N;
    int sum = 0;

    int arr[100] = {-1};

    cin >> M >> N;

    int size = judge(arr, M, N);

    if(size == 0){
        cout << "-1";
        return 0;
    }



    for(int i = 0; i < size; i++){
        sum += arr[i];
    }

    cout << sum << endl << arr[0];


}
