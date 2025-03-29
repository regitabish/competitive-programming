#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;  cin >> n;
    int mg; cin >> mg;
    //グラフG,Hを比較し、ある辺が存在するかのチェックには
    //メンバ関数countが便利なためこの問題では木の辺をset<pair<int,int>>の方で扱う
    set<pair<int,int>> edgesG;
    for(int i=0;i<mg;i++){
        int u,v;    cin >> u >> v;
        u--;
        v--;
        edgesG.insert({u,v});
        edgesG.insert({v,u});
    }
    int mh;     cin >> mh;

    set<pair<int,int>> edgesH;
    for(int i=0;i<mh;i++){
        int a,b;
        cin >> a >> b;
        a--;
        b--;
        edgesH.insert({a,b});
        edgesH.insert({b,a});
    }

    vector<vector<int>> a(n,vector<int>(n));
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;++j){
            int tmp;
            cin >> tmp;
            a[i][j] = tmp;
            a[j][i] = tmp;
        }
    }

    vector<int> p(n);
    //iotaはサイズnのVectorに対して0からnまでの数を埋める
    iota(begin(p),end(p),0);

    long long ans = 1e8;

    do{
        long long sum = 0;
        for(int i=0;i<n;++i){
            for(int j=0;j<i;++j){
                //問題文よりグラフHのi,jに対して操作する場合のコストがa[i][j]
                //なのでif(edgesH.count({i,j}) != edgesG.count({p[i],p[j]}))を調べる
                if(edgesH.count({i,j}) != edgesG.count({p[i],p[j]})){
                    sum += a[i][j];
                }
            }
        }
        ans = min(ans,sum);
    }while(next_permutation(p.begin(),p.end()));
    cout << ans << endl;
}