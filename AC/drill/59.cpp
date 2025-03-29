#include<bits/stdc++.h>
using namespace std;

int n1,n2,m;

long long maxDist(int start, vector<vector<int>> &to){
        queue<int>q;
        q.push(start);
        vector<long long> dist(n1+n2,-1);
        dist[start] = 0;
        long long ans=0;
        while(!q.empty()){
            int now = q.front();
            q.pop();
            for(auto next:to[now]){
                if(dist[next]==-1){
                    dist[next] = dist[now] + 1;
                    q.push(next);
                }
            }
        }
        for(auto d:dist)ans = max(ans,d);
        return ans;
    }

int main(){
    cin >> n1 >> n2 >> m;
    vector<vector<int>> to(n1+n2);
    for(int i=0;i<m;i++){
        int a,b;    cin >> a >> b;
        a--;
        b--;
        to[a].push_back(b);
        to[b].push_back(a);
    }

    
    cout << maxDist(0,to) + maxDist(n1+n2-1,to) + 1 << endl;
}