#include <iostream>

using namespace std;

int sets[9];

int r (int x){

    if(x == 0)
        return 1;

    int z = 1;

    for(int i = 0; i < x; i++){
        z*=10;
    }

    return z;
}

int dr(int T, int x){

    int z = 1;

    for(int i = 0; i < x; i++){
        z*=10;
    }

    return T/z;
}

void print(int arr[], int T, int index){


    for(int i = 0; i < index; i++){
        arr[i] = dr(T,index-i-1);
        T-= r(index-i-1) * arr[i];
    }

}



int main(){

    int count = 0;
    int T;
    int arr[6];
    int index;


    for(int i = 0; i < 9; i++){
        sets[i] = 1;
    }
    sets[6] = 2;

    scanf("%d", &T);

    if(T == 0){
        printf("1");
        return 0;
    }
    else if(T == 1000000){
        printf("6");
        return 0;
    }


    for(int i = 7; i >= 1; i--){
        if(T < r(i) && T>= r(i-1)){
            print(arr, T, i);
            index = i;
        }
    }


    for(int i = 0; i < index; i++){
        if(arr[i] == 9){
            sets[6]--;
            arr[i] = 6;
        }
        else
            sets[arr[i]]--;

        if(sets[arr[i]] == -1){

            for(int i = 0; i < 9; i++) {
                if (i == 6)
                    sets[6] += 2;
                else
                    sets[i]++;
            }
            count++;
        }

    }


    printf("%d", count+1);



    return 0;
}
