#include <bits/stdc++.h>
using namespace std;



int main(){
    int n,x,y;
    cin >> n >> x >> y;
    x--;
    y--;

    vector<vector<int>> to(n);
    for(int i=0;i<n-1;++i){
        int u,v;
        cin >> u >> v;
        u--;
        v--;
        to[u].push_back(v);
        to[v].push_back(u);
    }
    bool isPath = false ;
    
    vector<int> ans;

    auto dfs = [&](auto dfs,int now,int prev=-1)->void{
        
        if(now==y){
            isPath=true;
            //cout << "now" << now << endl;
        }
        //cout << now << endl;
        for(auto next:to[now]){
            if(prev==next)continue;
            
            if(isPath == false){
                dfs(dfs,next,now);
            }
            
        }
        if(isPath)ans.push_back(now);
    };

    dfs(dfs,x);
    reverse(ans.begin(),ans.end());
    for(auto a:ans)cout << a+1 << " ";
    cout << endl;
}
