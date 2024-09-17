#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,k;
    cin >> n >> k;

    vector<vector<int>> to(n);
    for(int i=0;i<n-1;i++){
        int a,b;
        cin >> a >> b;
        a--;
        b--;
        to[a].push_back(b);
        to[b].push_back(a);
    }

    vector<int> v;
    for(int i=0;i<k;i++){
        int tmp;    cin >> tmp;
        tmp--;
        v.push_back(tmp);
    }
    vector<bool> selected(n,false);
    for(int i=0;i<k;++i)selected[v[i]] = true;

    vector<int> score(n,0);
    auto dfs = [&](auto dfs,int now,int prev = -1)->void{
        if(selected[now]==true)score[now]++;
        for(auto next: to[now]){
            if(next == prev)continue;
            dfs(dfs,next,now);
            score[now]+=score[next];
        }
    };
    dfs(dfs,v[0]);

    long long ans = 0;
    for(auto a:score){
        if(a>0)ans++;
    }
    cout << ans << endl;
}