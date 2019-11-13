#include <iostream>
#include <cstring>

using namespace std;

int main(){


    char *arr = new char[999999];
    int *tmp = new int[26];
    int index = 0;
    int maxindex = 0;
    int count = 0;
    int max = -1;

    for(int i = 0; i < 26; i++)
        tmp[i] = 0;

    cin >> arr;

    int size = strlen(arr);

    for(int i = 0; i < size; i++){
        if((int)arr[i] > 64 && (int)arr[i] < 91){
            index = (int)arr[i] % 65;
            tmp[index]++;
        }

        if((int)arr[i] > 96 && (int)arr[i] < 123){
            index = (int)arr[i] % 97;
            tmp[index]++;
        }
    }

    for(int i = 0; i < 26; i++){
        if(max < tmp[i]) {
            max = tmp[i];
            maxindex = i;
        }
    }

    for(int i = 0; i < 26; i++){
        if(tmp[i] == max)
            count++;
    }

    if(count == 1){
        cout << (char)(maxindex+65);
    }
    else
        cout << "?";

    return 0;
}
