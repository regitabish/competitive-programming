#include<bits/stdc++.h>
using namespace std;
int n1,n2,m;

int maxDist(int start,vector<vector<int>>to){
    vector<int>dist(n1+n2,-1);
    dist[start] = 0;
    queue<int>q;
    q.push(start);
    while(!q.empty()){
        int now = q.front();
        q.pop();
        //cout << now << endl;
        for(auto next:to[now]){
            if(dist[next]==-1){
                dist[next] = dist[now] + 1;
                q.push(next);
            }
        }

    }

    int distMax = -1;
    for(auto d:dist){
        distMax = max(distMax,d);
    }
    return distMax;
}

int main(){
    
    cin >> n1 >> n2 >> m;
    vector<vector<int>>to(n1+n2);

    for(int i=0;i<m;i++){
        int a,b;
        cin >> a >> b;
        a--;
        b--;
        //cout << a << b << endl;
        to[a].push_back(b);
        to[b].push_back(a);
    }
    
    cout << maxDist(0,to) + maxDist(n1+n2-1,to) + 1 << endl;

}