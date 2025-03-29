#include<bits/stdc++.h>
using namespace std;

const long long N = 2e5+10;
vector<pair<long long,long long>> g[N];
bool vis[N];
long long ans[N];

void dfs(int x){
    if(vis[x])return;
    vis[x]=true;
    for(auto a:g[x]){
        long long next=a.first;
        long long weigh=a.second;
        if(!vis[next]){
            ans[next] = ans[x] + weigh;
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
    for(int i=0;i<n;++i)cout<<ans[i]<<" ";
    cout<<endl;

}