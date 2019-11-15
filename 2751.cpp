#include <iostream>

using namespace std;




void merge(int arr[], int p, int q, int r){

    int tmp[1000000];
    int i = p;
    int j = q+1;
    int t = 0;



    while(i<=q && j<=r){
        if(arr[i] < arr[j])
            tmp[t++] = arr[i++];
        else
            tmp[t++] = arr[j++];
    }

    while(i<=q)
        tmp[t++] = arr[i++];
    while(j<=r)
        tmp[t++] = arr[j++];

    t = 0;
    i = p;


    while(i <= r){
        arr[i++] = tmp[t++];
    }

}

void mergesort(int arr[], int p, int r){

    if(p < r){
        int q = (p + r) / 2;

        mergesort(arr, p,q);
        mergesort(arr, q+1,r);
        merge(arr, p, q, r);
    }

}

int main(){

    int T;

    scanf("%d", &T);

    int arr[1000000];

    for(int i = 0; i < T; i++)
        scanf("%d", &arr[i]);

    mergesort(arr, 0, T - 1);

    for(int i = 0; i < T; i++){
        printf("%d\n", arr[i]);
    }

    return 0;
}
