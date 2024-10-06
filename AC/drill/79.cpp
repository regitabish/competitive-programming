#include<bits/stdc++.h>
using namespace std;
int main(){
    int n1,n2,m;    cin >> n1 >> n2 >> m;
    vector<vector<int>> to(n1+n2);
    for(int i=0;i<m;++i){
        int a,b;    cin >> a >> b;
        a--;
        b--;
        to[a].push_back(b);
        to[b].push_back(a);
    }

    auto bfs = [&](int start)->int{
        vector<int>dist(n1+n2,-1);
        dist[0] = 0;
        dist[n1+n2-1] = 0;
        queue<int>q;
        q.push(start);
        while(!q.empty()){
            int now = q.front();
            //cout << now << "\n";
            q.pop();
            for(auto next: to[now]){
                if(dist[next]!=-1)continue;
                q.push(next);
                dist[next] = dist[now] + 1;
            }
        }
        int ans = -1;
        for(int i=0;i<n1+n2;++i){
            ans = max(ans,dist[i]);
        }
        return ans ;
    };

    cout << bfs(0) + bfs(n1+n2-1) + 1 << endl;
    return 0;

}