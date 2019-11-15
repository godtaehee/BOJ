#include <iostream>

using namespace std;

void push(int stack[], int * point){

    int a;
    int size = *point;

    cin >> a;
    stack[size] = a;
    *point +=1;


}

void pop(int stack[], int *point){

    int size = *point;

    if(size == 0){
        cout << "-1" << endl;
        return;
    }


    cout << stack[size -1] << endl;
    *point -=1;

}

void top(int stack[], int *point){

    int size = *point;

    if(size == 0){
        cout << "-1" << endl;
        return;
    }

    cout << stack[size - 1] << endl;
}


int main(){

    int n;
    int size = 0;
    int stack[10000];

    cin >> n;

    while(n--){

        string select;
        cin >> select;


        if(select == "push")
            push(stack, &size);

        else if(select == "pop")
            pop(stack, &size);

        else if(select == "size")
            cout << size << endl;

        else if(select == "empty"){
            if(size == 0)
                cout << "1" << endl;
            else
                cout << "0" << endl;
        }
        else if(select == "top")
            top(stack, &size);


    }


}
