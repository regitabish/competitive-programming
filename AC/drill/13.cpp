#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    int k;
    cin >> n >> k;

    vector<vector<int>> to(n);

    for(int i=0;i<n-1;++i){
        int a,b;
        cin >> a >> b;
        a--;
        b--;
        to[a].push_back(b);
        to[b].push_back(a);
    }
    
    vector<int>v;

    for(int i=0;i<k;++i){
        int tmp;
        cin >> tmp;
        tmp--;
        v.push_back(tmp);
    }

    vector<bool> selected(n);
    for(int i=0;i<k;++i)selected[v[i]]=true;
    
    vector<int> num(n);

    auto dfs = [&](auto dfs,int v,int p=-1)->void{
        if(selected[v])num[v]++;
        for(auto next:to[v]){
            if(p==next)continue;
            dfs(dfs,next,v);
            num[v]+=num[next];
        }
    };

    dfs(dfs,v[0]);
    int ans = 0;
    for(int i=0;i<n;i++){
        if(num[i]>0)ans++;
    }
    cout << ans << endl;

}