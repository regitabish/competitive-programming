
#include <bits/stdc++.h>
using namespace std;

int main() {

    int n,k;
    cin >> n >> k;
    vector<char> v(n);
    for(int i=0;i<n;i++){
        cin >> v.at(i);
    }
    sort(v.begin(),v.end());

    int ans = 0;
    bool ok,flag;

    do{
        ok = true;
        for(int i=0;i<=n-k;i++){
            flag = true;
            for(int j=0;j<k;j++){
                
                if(v.at(i+j) != v.at(i+k-j-1)){
                    flag = false;
                }
                
            }
            if(flag)ok = false;
        }
        if(ok)ans++;
    }while(next_permutation(v.begin(),v.end()));


    cout << ans << endl;
}
