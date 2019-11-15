#include <iostream>

using namespace std;

bool judge(int arr[], int x){

    for(int i = 0; i < 3; i++){
        arr[i]= x % 10;
        if(!arr[i])
            return false;
        x = x / 10;
    }
    return true;
}

int main(){

    int x,y;
    int arr[3];

    cin >> x >> y;

    if(x == y)
        return 0;

    if(judge(arr, x))
    x = 100 * arr[0] + 10 * arr[1] + arr[2];

   if(judge(arr, y))
    y = 100* arr[0] + 10 * arr[1] + arr[2];

    if(x>y)
        cout << x;
    else
        cout << y;



    return 0;
}
