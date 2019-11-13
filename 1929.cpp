#include<iostream>
#include<cmath>

using namespace std;

int v[1000001];
void get_ans(int n,int m);

int main()
{
    int n,m;
    cin>>n>>m;

    get_ans(n,m);
}
void get_ans(int n,int m)
{
    for(int i=2;i<=sqrt(m);i++)
    {
        for(int j=i+i;j<=m;j+=i)
            v[j]=1;
    }
    for(int i=n;i<=m;i++)
        if(!v[i] && i!=1)
            cout<<i<<"\n";
}
