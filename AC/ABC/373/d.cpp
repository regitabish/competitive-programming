#include<bits/stdc++.h>
using namespace std;

const long long N = 2e5+10;
const long long M = 1e9+10;
const long long INF = 1e17+10;

vector<pair<long long,long long>> g[N];
bool vis[N];
long long ans[N];

void dfs(int now){
    if(vis[now])return;
    vis[now] = true;

    for(auto a:g[now]){    
        long long next = a.first;
        long long weight = a.second;
        if(vis[next]==false){
            ans[next] = ans[now]+weight; 
            dfs(next);
        }
    }
}

int main(){
    long long n,m;  cin >> n >> m;
    for(int i=0;i<m;++i){
        long long u,v,w;
        cin >> u >> v >> w;
        u--;
        v--;
        g[u].push_back({v,w});
        g[v].push_back({u,-w});
    }
    for(int i=0;i<n;++i)dfs(i);
    for(int i=0;i<n;++i)cout << ans[i] << " ";
    cout << endl;
}