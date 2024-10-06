#include<bits/stdc++.h>
using namespace std;

vector<pair<int,int>>g(2e5+10);
vector<int> ans(2e5+10);

int main(){
    int n,m;    cin >> n >> m;
    for(int i=0;i<m;++i){
        int u,v,w;
        u--;
        v--;
        g[u].push_back({v,w});
        g[v].push_back({u,-w});
    }
    auto dfs = [&](auto dfs, int now){
        
    }
}