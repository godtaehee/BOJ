#include <stdio.h>

int main(){

    int T;
    int N;
    int sum = 0;
    int avg;

    scanf("%d", &T);

    while(T--){

        scanf("%d", &N);

        if(N < 1 || N > 1000)
            break;

        int score[N];
        int count = 0;

        for(int i = 0; i < N; i++){
            scanf("%d", &score[i]);
            if(score[i] < 0 || score[i] > 100)
                return 0;
            sum += score[i];
        }

        avg = sum / N;
        sum = 0;

        for(int i = 0; i < N; i++){
            if(score[i] > avg){
                count++;
            }
        }

        printf("%.3lf%%\n", ((double)count / N) * 100);

    }
    return 0;
}
