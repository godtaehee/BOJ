#include <iostream>
#include <cstring>

using namespace std;
int main(){

    int n, target;
    int f[1000][1000];
    memset(f, 0, sizeof(f));

    cin >> n;
    cin >> target;

    int row = n/2, column = n/2;
    f[row][column] = 1;
    int rotation = 0, count = 1, turn = 0, increaseCnt = 1;


    while(1){



        if(row == -1 && column == 0) {
            break;
        }

        if(rotation >= 2){
            rotation = 0;
            count+=1;
        }

        if(turn == 0){
            for(int i = 0; i < count; i++){
                f[row--][column] = increaseCnt++;
            }
        }else if(turn == 1){
            for(int i = 0; i < count; i++){
                f[row][column++] = increaseCnt++;
            }
        }else if(turn == 2){
            for(int i = 0; i < count; i++){
                f[row++][column] = increaseCnt++;
            }
        }else if(turn == 3){
            for(int i = 0; i < count; i++){
                f[row][column--] = increaseCnt++;
            }
        }

        turn++;
        rotation++;
        turn%=4;

    }

    int ansidx_i, ansidx_j;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(f[i][j] == target){
                ansidx_i = i;
                ansidx_j = j;
            }
            cout << f[i][j] << ' ';
        }
        cout << '\n';
    }

    cout << ansidx_i + 1 << ' ' << ansidx_j + 1 << '\n';



    return 0;
}
