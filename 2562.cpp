#include <iostream>

using namespace std;

int main(){

    int *a = new int[9];
    int index;

    for(int i = 0; i < 9; i++)
        scanf("%d", &a[i]);

    int max = -1;

    for(int i = 0; i < 9; i++){
        if(max < a[i]) {
            max = a[i];
            index = i;

        }
    }

    printf("%d\n%d", max, index+1);
    return 0;
}
