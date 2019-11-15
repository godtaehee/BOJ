#include <iostream>
#include <cstring>

using namespace std;

int main(){

    string x;
    int c = 0;
    int i = 0;
    bool t;

    cin >> x;

   while(i < x.length()){
       t = true;

        if(x[i] == 'n' && t){
            if(x[i+1] == 'j')
                i+=2;
            else
                i++;
            t = false;
        }

        if(x[i] == 'c' && t){
            if(x[i+1] == '=' || x[i+1] == '-')
                i+=2;
            else
                i++;
            t = false;
        }

        if(x[i] == 'd' && t){
            if(x[i+1] == 'z' && x[i+2] == '=')
                i+=3;
            else if(x[i+1] == '-')
                i+=2;
            else
                i++;
            t = false;
        }

        if(x[i] == 'l' && t){
            if(x[i+1] == 'j')
                i+=2;
            else
                i++;
            t = false;
        }

        if(x[i] == 's' && t){
            if(x[i+1] == '=')
                i+=2;
            else
                i++;
            t = false;
        }

        if(x[i] == 'z' && t){
            if(x[i+1] == '=')
                i+=2;
            else
                i++;
            t = false;
        }
        c++;
        if(t)
            i++;
    }

    cout << c;

    return 0;
}
