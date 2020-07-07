#include <iostream>
using namespace std;
int main(){
    string s;
    int n;
    cin >> n;
    cin >> s;
    int size = s.size();
    string result = s;
    for(int i = 0; i < n-1; i++){
        cin >> s;
        for(int j = 0; j < size; j++){
            if(result[j] != s[j])
                result[j] = '?';
        }
    }

    cout << result << '\n';
    return 0;
}
