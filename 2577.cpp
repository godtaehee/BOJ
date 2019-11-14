#include <iostream>

using namespace std;

int mypow(int x, int y){

    if(y == 0)
        return 1;

    int save = x;

    for(int i = 0; i < y; i++){
        x = x * save;
    }

    return x;
}


int confirm(int x){

    int value;

    for(int i = 0; i <= 9; i++){
        if(!(x / mypow(10, i))){
            value = i;
            break;
        }

    }

    return value + 1;

}

void result(int arr[], int n, int size){

    for(int i = 0; i < size; i++){
       arr[size - i - 1] = n % 10;
       n = n / 10;
    }



}

int main(){

    int a, b, c;

    cin >> a >> b >> c;

    int multiply;
    int size;
    int arr[10] = {0};
    int C[10];

    for(int i = 0; i < 10; i++)
        C[i] = 0;

    multiply = a * b * c;

    size = confirm(multiply);

    result(arr, multiply, size);

    for(int i = 0; i < size; i++){
        C[arr[i]]++;
    }

    for(int i = 0; i < 10; i++)
        cout << C[i] << endl;





}
