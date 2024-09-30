#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;  cin >> n;
    int mg; cin >> mg;
    set<pair<int,int>>graphG;
    for(int i=0;i<mg;i++){
        int u,v;    cin >> u >> v;
        u--;
        v--;
        graphG.insert({u,v});
        graphG.insert({v,u});
    }
    int mh; cin >> mh;
    set<pair<int,int>>graphH;
    for(int i=0;i<mh;++i){
        int a,b;    cin >> a >> b;
        a--;
        b--;
        graphH.insert({a,b});
        graphH.insert({b,a});
    }
    vector<int> p(n);
    for(int i=0;i<n;++i)p[i] = i;
    vector<vector<int>> a(n,vector<int>(n));

    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            cin >> a[i][j];
            a[j][i] = a[i][j];
        }
    }
    long long ans = 1e18;
    do{
        long long score = 0;
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                if(graphH.count({i,j})!=graphG.count({p[i],p[j]})){
                    score += a[i][j];
                }
            }
        }
        
        ans = min(ans, score);
    }while(next_permutation(p.begin(),p.end()));

    cout << ans << endl;
}