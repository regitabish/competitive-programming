#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;  cin >> n;
    
    set<pair<int,int>> edges_G,edges_H;
    int Mg; cin >> Mg;
    for(int i=0;i<Mg;i++){
        int u,v;
        cin >> u >> v;
        u--;
        v--;
        edges_G.insert({u,v});
        edges_G.insert({v,u});
    }

    int Mh; cin >> Mh;
    for(int i=0;i<Mh;++i){
        int a,b;
        cin >> a >> b;
        a--;
        b--;
        edges_H.insert({a,b});
        edges_H.insert({b,a});
    }
    vector<vector<int>> a(n,vector<int>(n));
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            int tmp;    cin >> tmp;
            a[i][j] = tmp;
            a[j][i] = tmp;
        }
    }

    vector<int> p(n);
    //iotaはサイズnのVectorに対して0からnまでの数を埋める
    iota(begin(p),end(p),0);

    int ans = 1e8;
    
    do{
        int sum = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;++j){
                if( edges_H.count({i, j}) != edges_G.count({p[i], p[j]}) ){
                    sum += a[i][j];
                }
            }
        }
        //cout << sum << endl;
        ans = min(ans, sum);
        sum = 0;
    }while(next_permutation(p.begin(),p.end()));

    cout << ans << endl;
}