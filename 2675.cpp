#include <iostream>
#include <cstring>

using namespace std;

int main(){

    int T;
    int count = 0;
    int length = 0;
    char *arr = new char[20];

    cin >> T;

    while(T--){

        cin >> count >> arr;

        length = strlen(arr);

        for(int i = 0; i < length; i++){
            for(int j = 0; j < count; j++){
                cout << arr[i];
            }
        }

        cout << endl;
    }

    return 0;
}
