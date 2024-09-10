#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,k;    cin >> n >> k;

    vector<vector<int>> to(n);
    for(int i=0;i<n-1;++i){
        int a,b;
        cin >> a >> b;
        a--;
        b--;
        to[a].push_back(b);
        to[b].push_back(a);

    }
    vector<int> v;
    for(int i=0;i<k;++i){
        int tmp; cin >> tmp;
        tmp--;
        v.push_back(tmp);
    }

    vector<bool> selected(n,false);
    for(int i=0;i<k;++i){
        selected[v[i]]=true;
        /*  cout << "selected " << v[i] << endl;
        cout << "i " << i << endl; */
    }
    vector<int>score(n,0);
    auto dfs = [&](auto dfs,int now, int prev=-1)->void{
        
        if(selected[now]==true){
            score[now]++;
            //cout << "now " << now << endl;
        }
        for(auto next: to[now]){
            if(next==prev)continue;//前には戻らない
            dfs(dfs,next,now);
            score[now]+=score[next];
        }
    };

    dfs(dfs,v[0]);

    int ans = 0;
    for(int i=0;i<n;i++){
        if(score[i]>0){
            ans++;
            //cout << i << endl;
        }
    }

    cout << ans << endl;

}