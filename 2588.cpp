#include <iostream>

using namespace std;

int main(){

    int a, b;

    int bb[3];
    int result[3];
    int sum;

    scanf("%d %d", &a, &b);
    
    if(a < 100 || b < 100)
        return 0;

    bb[0] = b / 100;
    b-= (100*bb[0]);
    bb[1] = b/10;
    b-= (10*bb[1]);
    bb[2] = b;

    result[0] = a * b;
    result[1] = a * bb[1];
    result[2] = a* bb[0];

    sum = result[0] + result[1] * 10 + result[2] * 100;

    for(int i = 0; i < 3; i++)
        printf("%d\n", result[i]);
    printf("%d", sum);
    return 0;
}
