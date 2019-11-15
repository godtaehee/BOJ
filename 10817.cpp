#include <iostream>

using namespace std;

int main(){

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int a[3];
    int tmp;


    for(int i = 0; i < 3; i++)
        cin >> a[i];

    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            if(a[j] >= a[j+1]){
                tmp = a[j];
                a[j] = a[j+1];
                a[j+1] = tmp;
            }
        }
    }

    cout << a[1];

}
