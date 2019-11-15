#include <iostream>
#include <string>

using namespace std;


string valid(string arr){
    int cnt = 0;


    for(int i = 0; i < arr.size(); i++){
        if(arr[i] == '(')
            cnt+=1;
        else
            cnt-= 1;

        if (cnt < 0) {
            return "NO";
        }
        
    }


    if (cnt == 0) {
        return "YES";
    } else {
        return "NO";
    }

}


int main(){


    int T;

    cin >> T;

    while(T--){
        string stack;
        cin >> stack;
        cout << valid(stack) << endl;
    }

    return 0;
}
