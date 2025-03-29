
#include <bits/stdc++.h>
using namespace std;

int main() {

    int n,q;
    cin >> n>>q;
    int a[n];
    
    map<int,vector<int>>mp;

    for(int i=0;i<n;i++){
        cin >> a[i];
        mp[a[i]].push_back(i+1);
    }
    

    vector<int>ans;
    for(int i=0;i<q;i++){
        int x,k;
        cin >>x >> k;

        if(k<=mp[x].size()){
            ans.push_back(mp[x].at(k-1));
        }else ans.push_back(-1);
    }

    cout << 222 << endl;
    for(auto a: ans)cout << a << endl;

}
