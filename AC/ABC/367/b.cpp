
#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;

    while(s.at(s.size()-1) == '0' ||  s.at(s.size()-1) == '.'){
        
        if(s == "0"){
            break;
        }
        if(s.at(s.size()-1) == '.'){
            s.replace(s.size()-1,1,"");
            break;
        }
        s.replace(s.size()-1,1,"");
    }

    cout << s << endl;
    
}
