#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;  cin >> n;
    int mg; cin >> mg;
    vector<vector<int>> g_edges(n+1);
    for(int i=0;i<mg;++i){
        int u,v;    cin >> u >> v;
        g_edges[u].push_back(v);
        g_edges[v].push_back(u);
    }

    int mh; cin >> mh;
    vector<vector<int>> h_edges(n+1);
    for(int i=0;i<mh;++i){
        int a,b;    cin >> a >> b;
        h_edges[a].push_back(b);
        h_edges[b].push_back(a);
    }

    vector<vector<int>> a(n+1,vector<int>(n+1));
    for(int i=1;i<n;++i){
        for(int j=i+1;j<=n;j++){
            cin >> a[i][j];
            a[j][i] = a[i][j];
        }
    }
    //cout << 22 << endl;
    vector<int> p(n-1);
    for(int i=0;i<n-1;i++)p[i] = i+1;
    int cost = 1e18;
    
    do{
        int sum = 0;
        //cout << 222222222222222 << endl;
        /* for(auto a:p)cout << a << " ";
        cout << endl; */
        for(int i=1;i<=n;++i){
            for(int j=i;j<=n;j++){
                cout << i << " " << j << " " << p[i-1] << " " << p[j-1] << endl;
                if(g_edges[i][j] != h_edges[p[i-1]][p[j-1]]){
                    sum += a[i][j];
                }
            }
        }
        cost = min(cost,sum);
        
        
    }while(next_permutation(p.begin(),p.end()));
    
    cout << cost << endl;
}