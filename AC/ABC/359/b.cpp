
#include <bits/stdc++.h>
using namespace std;

int main() {

    int n;cin >> n;
    vector<string>c;
    int ans=0 ;
    for(int i=0;i<2*n;i++){
        string tmp;
        cin >> tmp;
        c.push_back(tmp);
    }

    for(int i=0;i<2*n-2;i++){
        //cout << i << " " << c.at(i) << endl;
        if(c.at(i)==c.at(i+2)){
            //cout << c.at(i) <<endl;
            ans++;
        }
    }

    cout << ans << endl;
}
