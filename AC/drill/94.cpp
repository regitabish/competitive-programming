#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,q;    cin >> n >> q;
    map<int, vector<int>>mp;
    for(int i=0;i<n;++i){
        int tmp;    cin >> tmp;
        mp[tmp].push_back(i+1);
    }
    vector<int> ans(q);
    for(int i=0;i<q;++i){
        int x,k;    cin >> x >> k;
        if(mp[x].size()<k)ans.at(i)=-1;
        else{
            ans.at(i) = mp[x].at(k-1);
        }
    }
    for(int i=0;i<q;++i)cout << ans.at(i) << "\n";

}