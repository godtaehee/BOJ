#include <iostream>

using namespace std;

int sum(int x){

    int sum = (x * (x+1)) / 2;
    return sum;
}

void judge(int x){

    if(x == 1)
        cout << "1";

    int p;
    int q;
    int l = 1;
    int j = 0;


    while(1){
        p = sum(l) + 1;
        q = sum(l+1);
        if(x >= p && x <= q)
            break;
        l++;
    }


    int presum = sum(l);


    for(int i = presum + 1; i <= presum + l + 1; i++){
        if(x != i){
            j++;
        }else
            break;

    }

    if((l+1)% 2 == 0)
    cout << j + 1 << '/' << (l+2) - (j+1);
    else
        cout << l - j + 1 << '/' << j+1;
}


int main(){

    int n;

    cin >> n;

    judge(n);

    return 0;
}
