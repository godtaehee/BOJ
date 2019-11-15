#include <stdio.h>

int main(){
    int a, b;

    scanf("%d %d", &a, &b);

    if(a < 1){
        return 0;
    }
    else if(b < 1 && b > 10000){
        return 0;
    }
    else
        printf("%d\n%d\n%d\n%d\n%d\n", a+b, a-b, a*b, a/b, a%b);
}
