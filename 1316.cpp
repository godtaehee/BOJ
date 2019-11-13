#include <iostream>
#include <cstring>

using namespace std;

int main(){

    int T;

    string x;
    string arr[100];
    int tmp[26];

    int count = 0;
    int index = 0;
    bool wrong;
    bool game;

    cin >> T;

    while(T--){

        for(int i = 0; i < 26; i++)
            tmp[i] = 0;

        wrong = true;
        game = true;

        cin >> x;



        arr[index++] = x;

        if(x.length() == 1){
            count++;
            continue;
        }

        if(index-1 != 0){
            for(int i = 0; i < index - 1; i++){
                if(x == arr[i])
                    wrong = false;
            }
        }

        if(!wrong)
            continue;


        for(int i = 0; i < x.length(); i++){
            int p = (int)x[i] % 97;
            tmp[p]++;

            if(tmp[p] > 1){
                if(x[i-1] != x[i]){
                    game = false;
                }
            }
        }

        if(game)
            count++;

    }

    cout << count;

    return 0;
}
