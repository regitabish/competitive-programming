#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;  cin >> n;
    int m=0;
    string s[n];
    for(int i=0;i<n;i++){
        cin >> s[i];
        m=max(m,int(s[i].size()) );
    }

    for(int i=0;i<m;i++){
        for(int j=n-1;j<=0;j--){
            cout<<s[j][i];
            //cout <<endl;
        }cout << endl;
    }


}