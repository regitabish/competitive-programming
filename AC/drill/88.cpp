#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,k;    cin >> n >> k;
    vector<vector<int>> to(n); 
    vector<int> score(n,0);
    vector<bool> vis(n,false);
    set<int> v;
    for(int i=0;i<n-1;i++){
        int a,b;    cin >> a >> b;
        a--;
        b--;
        to[a].push_back(b);
        to[b].push_back(a);
    }
    
    for(int i=0;i<k;++i){
        int tmp;
        cin >> tmp;
        tmp--;
        v.insert(tmp);
    }

    auto dfs = [&](auto dfs,int now)->void{
        int val = 0;
        if(v.count(now)>0)val=1;
        score[now] += val;
        vis[now] = true;
        for(auto next:to[now]){
            if(vis[next])continue;
            //cout << next << " " << now << endl;
            dfs(dfs,next);
            score[now] += score[next];
        }
        
    };
    int start =0;
    for(int i=0;i<n;++i){
        if(v.count(i)>0){
            start = i;
            break;
        }
    }
    dfs(dfs,start);
    long long ans = 0;
    for(int i=0;i<n;++i)if(score[i]>0){
        ans++;
        //cout << i+1 << endl;
    }
    cout << ans << endl;

}