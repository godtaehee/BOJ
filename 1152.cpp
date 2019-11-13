#include <iostream>
#include <cstring>

using namespace std;

int main(){

    char line[1000000];

    int count = 0;

    cin.getline(line, 1000000, '\n');

    int size = strlen(line);

    for(int i = 0; i < size; i++){
        if(line[i] != ' ' && line[i+1] == ' ')
            count++;
        else if(line[i] != ' ' && line[i+1] == '\0')
            count++;
    }

    cout << count;

    return 0;
}
