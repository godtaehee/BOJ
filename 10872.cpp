#include <iostream>

using namespace std;

int main(){

    int N;
    int result = 1;


    scanf("%d", &N);

    for(int i = 2; i <= N; i++){
        result*=i;
    }

    printf("%d", result);
    return 0;
}
