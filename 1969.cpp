#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>


using namespace std;

#define for(i,n) for(int i = 0; i < (n); i++)
struct dna{
    string sentence;
};

int judge(char x){
    if(x == 'A') return 0;
    else if(x == 'C') return 1;
    else if(x == 'G') return 2;
    else if(x == 'T') return 3;
}

char chJudge(int x){
    if(x==0)
        return 'A';
    else if(x==1)
        return 'C';
    else if(x==2)
        return 'G';
    else return 'T';
}
int main(){

    int n, m;
    vector<dna> f;
    cin >> n >> m;

    for(i,n){
        dna tmp;
        string x;
        cin >> x;
        tmp.sentence = x;
        f.push_back(tmp);
    }

    int cnt[4] = {0,0,0,0};

    string ans = "";
    int ansDigit = 0;
    for(i,m) {
        memset(cnt, 0, sizeof(cnt));
        for(j, n) {
            cnt[judge(f[j].sentence[i])]++;
        }
        int max = -1;
        int maxidx = 0;
        for(j, 4) {
            if (max < cnt[j]) {
                max = cnt[j];
                maxidx = j;
            }
        }

        ans += chJudge(maxidx);

    }

    for(i,m) {
        for(j, n) {
            if(f[j].sentence[i] != ans[i]) ansDigit++;
        }
    }
    cout << ans << '\n' << ansDigit << '\n';

    return 0;
}
