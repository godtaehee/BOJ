 가능한 체스판 2개를 만들고 그 체스판을 비교하면 확실하게 최소값을 구할수 있었다.

#include <iostream>
using  namespace std;
int main(){

    int n, m;
    char f[51][51];
    // 체스판 1
    char check1[8][8] = {{'W','B','W','B','W','B','W','B'},
                         {'B','W','B','W','B','W','B','W'},
                         {'W','B','W','B','W','B','W','B'},
                         {'B','W','B','W','B','W','B','W'},
                         {'W','B','W','B','W','B','W','B'},
                         {'B','W','B','W','B','W','B','W'},
                         {'W','B','W','B','W','B','W','B'},
                         {'B','W','B','W','B','W','B','W'},};

    //체스판 2
    char check2[8][8] = {{'B','W','B','W','B','W','B','W'},
                         {'W','B','W','B','W','B','W','B'},
                         {'B','W','B','W','B','W','B','W'},
                         {'W','B','W','B','W','B','W','B'},
                         {'B','W','B','W','B','W','B','W'},
                         {'W','B','W','B','W','B','W','B'},
                         {'B','W','B','W','B','W','B','W'},
                         {'W','B','W','B','W','B','W','B'},};
    cin >> n >> m;

    for(int i = 0; i < n; i++){
        cin >> f[i];
    }

    int min_value = 50000000; // 최대 고쳐야하는 횟수를 50*50이라고 생각하고 2500보다 큰수 아무거나



    for(int i = 0; i < n; i++){ // ---> 1번 for문
        for(int j = 0; j < m; j++){ // ---> 2번 for문
            int sum1 = 0;
            int sum2 = 0;
            if(i+7 < n && j+7 < m){
                for(int k = i; k <= i+7; k++){ // ---> 3번 for문
                    for(int z = j; z <= j+7; z++){ // ---> 4번 for문
                        if(check1[k-i][z-j] != f[k][z]) sum1++;
                        if(check2[k-i][z-j] != f[k][z]) sum2++;
                    }
                }
                int result = min(sum1,sum2);
                min_value = min(result,min_value);
            }
        }
    }

    cout << min_value << '\n';

    return 0;
}
