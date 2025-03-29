#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+10;
vector<pair<int,int>> g[N];
bool vis[N];
long long ans[N];
int main(){
    int n;  cin >> n;
    int m;  cin >> m;
    for(int i=0;i<m;++i){
        int u,v,w;
        cin >> u >> v >> w;
        u--;
        v--;
        g[u].push_back({v,w});
        g[v].push_back({u,-w});
    }

    auto dfs = [&](auto dfs,int now)->void {
        if(vis[now])return;
        vis[now] = true;
        for(auto i:g[now]){
            int next = i.first;
            int weight = i.second;
            ans[next] = ans[now] + weight;
            dfs(dfs,next);
        }
    };
    for(int i=0;i<n;++i)dfs(dfs,i);
    for(int i=0;i<n;++i)cout<<ans[i]<<" ";
    cout<<endl;
}