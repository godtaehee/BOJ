#include <iostream>
#include <cstring>

using namespace std;

int main(){

    int n;
    int sum = 0;

    char test[80];
    int cal[80];

    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> test;
        int size = strlen(test);

        for(int i = 0; i < size; i++)
            cal[i] = 0;

        for(int i = 0; i < size; i++) {
            if (test[i] == 'O')
                cal[i]++;
            else
                cal[i] = 0;
        }



        for(int i = 1; i < size; i++){
            if(cal[i])
                cal[i] = cal[i-1] + cal[i];
        }

/*        for(int i = 0; i < size; i++)
            cout << cal[i];
        cout << endl;*/

        for(int i = 0; i < size; i++)
            sum += cal[i];



        cout << sum << endl;

        sum = 0;

        for(int i = 0; i < size; i++)
            cal[i] = 0;
    }







}
