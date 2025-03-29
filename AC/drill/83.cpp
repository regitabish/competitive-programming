#include<bits/stdc++.h>
using namespace std;

const long long N = 2e5+10;

vector<pair<long long, long long>>g[N];
bool visited[N];
long long ans[N];

void dfs(int now){
    if(visited[now])return;
    visited[now] = true;
    for(auto a:g[now]){
        auto next   = a.first;
        auto weight = a.second;
        if(visited[next]==false){
            ans[next] = ans[now] + weight;
            dfs(next);
        }
    }
}

int main(){
    int n,m;    cin >> n >> m;
    for(int i=0;i<m;++i){
        int u,v,w;  cin >> u >> v >> w;
        u--;
        v--;
        g[u].push_back({v,w});
        g[v].push_back({u,-w});
    }

    for(int i=0;i<n;++i)dfs(i);
    for(int i=0;i<n;++i)cout << ans[i] << " ";
    cout << endl;
    return 0;

}