#include <stdio.h>

void d(){

    int x,y,w;
    int arr[10001] = {0};

    for(int n = 1; n < 10001; n++){

        if(n < 10 && n > 0)
            arr[2 * n]++;

        else if(n >= 10 && n < 100){
            arr[n + n / 10 + n % 10]++;
        }

        else if(n >= 100 && n < 1000){
            x = n / 100;
            y = (n - x * 100) / 10;
            arr[n + x + y + n % 10]++;

        }

        else if(n >= 1000  && n < 10000){
            x = n / 1000;
            y = (n - x * 1000) / 100;
            w = (n - x * 1000 - y * 100) / 10;

            if((n + x + y + w + n % 10) <= 10000)
                arr[n + x + y + w + n % 10]++;


        }

    }

    for(int i = 1; i < 10001; i++){
        if(arr[i] == 0)
            printf("%d\n", i);
    }

}
int main(){d();}
