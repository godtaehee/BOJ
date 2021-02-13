#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

void insertSort(vector<int> &a){
    int size = a.size();
    for(int i = 0; i < size; i++){
        int j = i;
        while(j>0 && a[j-1] > a[j]){
            swap(a[j-1],a[j]);
            j--;
        }
    }
}



int main(){


    int n;
    cin >> n;
    vector<int> a;
    for(int i = 0; i < n; i++){
        a.push_back(rand()%100);
    }

    cout << "전: ";
    for(auto x : a)
        cout << x << ' ';
    cout << '\n';
    insertSort(a);

    cout << "후: ";
    for(auto x : a)
        cout << x << ' ';
    cout << '\n';

    return 0;
}
