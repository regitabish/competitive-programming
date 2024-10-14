#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;  cin >> n;
    int mg; cin >> mg;
    vector<set<int>> g(n);
    for(int i=0;i<mg;++i){
        int u,v;    cin >> u >> v;
        u--;
        v--;
        g[u].insert(v);
        g[v].insert(u);
    }
    int mh; cin >> mh;
    vector<set<int>> h(n);
    for(int i=0;i<mh;++i){
        int u,v;    cin >> u >> v;
        u--;
        v--;
        h[u].insert(v);
        h[v].insert(u);
    }

    vector<vector<int>> a(n,vector<int>(n,0));
    for(int i=0;i<n-1;++i){
        for(int j=i+1;j<n;++j){
            cin >> a[i][j];
            a[j][i] = a[i][j];
        }
    }

    vector<int> v(n);
    for(int i=0;i<n;++i)v[i] = i;
    long long ans = 1e18;
    do{
        long long sum = 0;
        for(int i=0;i<n-1;++i){
            for(int j=i+1;j<n;++j){
                if(g[v[i]].count(v[j]) != h[i].count(j)){
                    sum += a[i][j];
                }
            }
        }
        ans = min(ans, sum);
    }while(next_permutation(v.begin(),v.end()));

    cout << ans << "\n";
} 