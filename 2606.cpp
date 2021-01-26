#include <iostream>
#include <vector>
using namespace std;
// vector<int> parent[101];
int parent[101];
int find(int a){
    if(parent[a] == a){
        return a;
    }
    parent[a] = find(parent[a]);
    return parent[a];
}
void unionFunc(int a, int b){
    int parentA = find(a);
    int parentB = find(b);

    int smaller = min(parentA, parentB);
    int bigger = parentA == smaller ? parentB : parentA;
    //작은수가 항상 부모가 됨
    parent[bigger]  = smaller;
}
int main(void){

    int n, pairs;
    cin >> n >> pairs;

    for(int i=1; i < n + 1; i++){
        parent[i] = i;
    }
    for(int i=0; i < pairs; i++){
        int numA, numB;
        cin >> numA >> numB;
        unionFunc(numA, numB);

    }
    int answer = 0;
    for(int i=1; i < n + 1; i++){
        if(find(parent[i]) == 1){
            answer++;
        }
    }
    //자기자신 제외
    cout << (answer - 1);
}
