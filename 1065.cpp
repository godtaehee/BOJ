// 2자리수는 무조건 한수

#include <iostream>

using namespace std;

void d(){
    int x, y, N, count = 0;
    cin >> N;

    if(N>99){
        for(int i = 100; i <= N; i++){

            x = i / 100;
            y = (i - 100 * x) / 10; // 두번째 자리수

            if(x-y == (y - i % 10))
                count++;
        }
        cout << count + 99;
    }
    else{
        for(int i = 1; i<=N; i++)
            count++;
            cout << count;
    }
}

int main(){d();}
