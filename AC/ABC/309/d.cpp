#include <bits/stdc++.h>
using namespace std;

int getDistOnTree(int start,vector<vector<int>> to){
    int n=to.size();
    vector<int> dist(n,-1);
    //cout << endl;
    dist[start]=0;
    queue<int>q;
    q.push(start);
    while(!q.empty()){

        int now = q.front();
        q.pop();
        for(auto next: to[now]){
            //cout << "next; " << next+1 << endl;
            if(dist[next]==-1){
                dist[next]=dist[now]+1;
                //cout << dist[next] << ";dist next" << endl;
                q.push(next);
            }
        }
    }
    int maxDist = -1;
    for(int i=0;i<n;i++){
        maxDist = max(maxDist,dist[i]);
    }
    //cout << maxDist << endl;
    return maxDist;
}

int main(){
    int n1,n2,m;
    cin >> n1 >> n2 >> m;
    
    vector<vector<int>> to(n1+n2);
    
    for(int i=0;i<m;++i){
        int a,b;
        cin >> a >> b;
        a--;
        b--;
        to[a].push_back(b);
        to[b].push_back(a);
    }

    cout << getDistOnTree(0,to) + getDistOnTree(n1+n2-1,to) + 1 << endl;
}
