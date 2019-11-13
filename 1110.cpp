#include <iostream>

using namespace std;

int main(){

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N, s, count = 0;
    bool T = true;
    int front, back;

    cin >> N;

     if(N < 0 || N > 100)
         return 0;

    s = N;

    while(T){

        if(N < 10){
            N = N * 10 + N;
            count ++;
            if(s == N){
                printf("%d", count);
                break;
            }

        }

        front = N / 10;
        back = N % 10;

        N = back * 10 + (front + back) % 10;
        count++;

        if(s == N){
            T = false;
            printf("%d", count);
        }

    }
}
