#include <bits/stdc++.h>
using namespace std;

int main(){
    int y;cin >>y;

    if(y%4!=0){
        cout << 365 << endl;
        return 0;
    }else if(y%100!=0){
        cout << 366 << endl;
        return 0;
    }else if(y%400!=0){
        cout << 365 << endl;
        return 0;
    }else {
        cout << 366 << endl;
        return 0;
    }
}