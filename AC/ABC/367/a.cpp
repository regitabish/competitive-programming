
#include <bits/stdc++.h>
using namespace std;

int main() {

    int a,b,c;cin>>a>>b>>c;
    int t=b;
    
    while(1){
        if(t==a){
            cout << "No" << endl;
            return 0;
        }

        if(t==c){
            cout << "Yes" << endl;
            return 0;
        }
        t++;
        t%=24
    }
}
