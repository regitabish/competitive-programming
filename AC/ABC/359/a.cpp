
#include <bits/stdc++.h>
using namespace std;

int main() {

    int n;cin >> n;
    vector<string>s;
    int ans=0 ;
    for(int i=0;i<n;i++){
        string tmp;
        cin >> tmp;
        if(tmp == "Takahashi")ans++;
    }

    cout << ans << endl;
}
