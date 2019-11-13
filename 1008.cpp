#include <stdio.h>

int main(){
    double a, b;

    scanf("%lf %lf", &a, &b);

    if(a < 0){
        return 0;
    }
    else if(b <0 && b > 10){
        return 0;
    }
    else
        printf("%.9lf", a/b);
}
