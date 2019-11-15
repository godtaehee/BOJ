#include <iostream>

using namespace std;

int main(){

    int N;
    int x, y;
    int min = 10000;

    cin >> N;

    x = N/3;
    y = N/5;


    for(int i = 0; i <= x; i++){
        for(int j = 0; j <= y; j++){
            if(3 * i + 5 * j == N){
                if(min > i+j){
                    min = i+j;
                }
            }
        }
    }

    if(min == 10000)
        min = -1;

    cout << min;

}
