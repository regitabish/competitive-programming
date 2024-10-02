#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,q;    cin >> n >> q;
    map<long long, vector<long long>>mp;

    for(int i=1;i<=n;++i){
        int a;  cin >> a;
        mp[a].push_back(i);
        cout << mp[a][i] << endl;
    }
    vector<long long> ans;
    
    for(int i=0;i<q;++i){
        int x,k;    cin >> x >> k;
        if(mp[x].size()>k){
            ans.push_back(-1);
        }
        else{
            //cout << mp[x][k] << endl;
            ans.push_back(mp[x][k-1]);
        }
        //cout << i << endl;
    }
    cout << endl;
    for(auto a:ans)cout << a << " ";
    cout << endl;
    return 0;

}