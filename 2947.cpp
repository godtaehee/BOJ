#include <iostream>
using namespace std;
int f[5];

void go(){
    for(int i = 0; i < 4; i++){
        if(f[i] > f[i+1]){
            swap(f[i],f[i+1]);
            for(int j = 0; j < 5; j++){
                cout << f[j] << ' ';
            }
            cout << '\n';
        }
    }
}
int main(){

    for(int i = 0; i < 5; i++){
        cin >> f[i];
    }

    while(1){
        go();
        int cnt = 0;
        for(int i = 0; i < 5; i++){
            if(f[i] == i+1) {
                cnt++;
            }
        }
        if(cnt == 5) break;
    }


    return 0;
}
