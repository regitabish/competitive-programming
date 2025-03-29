
#include <bits/stdc++.h>
using namespace std;

int main() {

    string s;
    cin >> s;

    for(int i=0;i<3;i++){
        if(s[i]=='R'){
            cout << "Yes" << endl;
            return 0;
        }
        if(s[i]=='M'){
            cout << "No" << endl;
            return 0;
        }
    }
}
