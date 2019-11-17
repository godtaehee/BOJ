#include <iostream>
#include <math.h>

using namespace std;

int main() {

    int T;
    int answer = 0;
    bool p[300000] = {false};
    p[1] = true;

    for(int i = 2; i < sqrt(300000); i++){
        for(int j = 2;  i *  j < 300000; j++){
            if(!p[i*j])
                p[i*j] = true;
        }
    }

    while(1){
        cin >> T;

        if(!T)
            break;

        for(int i = T+1; i <= 2 * T; i++){
            if(!p[i])
                answer++;
        }

        cout << answer << endl;
        answer = 0;


    }

    return 0;
}
