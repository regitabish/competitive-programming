#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;  cin >> n;
    int mg; cin >> mg;
    set<pair<int,int>> graph_g;
    for(int i=0;i<mg;i++){
        int u,v;    cin >> u >> v;
        u--;
        v--;
        graph_g.insert({u,v});
        graph_g.insert({v,u});
    }
    int mh; cin >> mh;
    set<pair<int,int>>graph_h;
    for(int i=0;i<mh;i++){
        int a,b;    cin >> a >> b;
        a--;
        b--;
        graph_h.insert({a,b});
        graph_h.insert({b,a});
    }

    vector<vector<int>> a(n,vector<int>(n));

    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            cin >> a[i][j];
            a[j][i] = a[i][j];
        }
    }
    vector<int> p(n);
    for(int i=0;i<n;i++)p[i] = i;
    long long ans = 1e18;
    do{
        long long cost = 0;
        for(int i=0;i<n-1;i++){
            for(int j=i;j<n;j++){
                if(graph_h.count({i,j}) != graph_g.count({p[i],p[j]})){
                    cost+=a[i][j];
                }
            }
        }
        ans = min(ans,cost);
    }while(next_permutation(p.begin(),p.end()));
    cout << ans << endl;
}