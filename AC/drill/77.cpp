#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,q;    cin >> n >> q;
    vector<int> a(n);
    map<int, vector<int>>mp;
    for(int i=0;i<n;++i){
        cin >> a[i];
        mp[a[i]].push_back(i+1);
    }
    vector<int> ans;
    
    for(int i=0;i<q;i++){
        int x,k;    cin >> x >> k;
        if(mp[x].size()<k)ans.push_back(-1);
        else ans.push_back(mp[x][k-1]);
    }
    for(auto a:ans)cout << a << "\n";
    return 0;
}