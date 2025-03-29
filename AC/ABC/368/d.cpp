#include <bits/stdc++.h>

using namespace std;

int main(){
    int n,k;cin>>n>>k;
    vector<vector<int>> g(n);
    for(int i=0;i<n-1;++i){
        int a,b;
        cin >> a >> b;
        a--;
        b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    vector<int> v;
    for(int i=0;i<k;++i){
        int tmp;
        cin >> tmp;
        tmp--;
        v.push_back(tmp);
    }
    vector<bool> selected(n); //各頂点に対し、その頂点が選ばれているかを管理する。
    for(int i=0;i<k;i++){
        selected[v[i]]=true;
    }
    vector<int>num(n);
    auto dfs = [&](auto dfs, int v,int p=-1) -> void{ //ラムダ式の書き方よく勉強すること
        //関数自体はvがいまいる頂点番号,pがこの直前の頂点番号
        if(selected[v])num[v]++; //v自身が必要な頂点であればnumにインクリメント
        for(auto to:g[v]){
            if(to==p)continue;
            dfs(dfs,to,v);

            //toで得られたnumたちもvのnumに足す。この時点でtoのnumたちはすべてそろっている.
            //ここの動作で自身が与えられた残すべき頂点ではないが、子以下に与えられた必要頂点がいる頂店vを拾う。
            num[v]+=num[to];    

        }
    };
    dfs(dfs,v[0]); //必要頂点の一つからdfsを始める
    int ans = 0;
    for(int i=0;i<n;++i){
        if(num[i]>0)ans++;
    }
    cout << ans << endl;
    return 0;
}