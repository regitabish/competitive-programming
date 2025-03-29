#include <bits/stdc++.h>
using namespace std;
int n1,n2,m;

int maxDist(int start,vector<vector<int>> to){
    queue<int>q;
    q.push(start);
    vector<int> dist(n1+n2,-1);
    //cout << start << endl;
    dist[start] = 0;
    while(!q.empty()){
        int now = q.front();
        q.pop();
        
        for(auto next:to[now]){
            
            if(dist[next]==-1){
                //このタイミングで更新すればnowの隣の頂点の距離を更新できる
                dist[next] = dist[now]+1;
                q.push(next);
                //cout << next << endl;
            }
        }
    }

    int maxD = -1000;
    //cout << maxD << endl;
    for(auto d:dist){
    //    cout << d << " " ;
        maxD = max(d,maxD);
    }
    //cout << maxD << endl;
    return maxD;
}

int main(){
    
    cin >> n1 >> n2 >> m;
    vector<vector<int>> to(n1+n2);
    for(int i=0;i<m;i++){
        int a,b;
        cin >> a >> b;
        a--;
        b--;
        //cout << a << b << endl;
        to[a].push_back(b);
        to[b].push_back(a);
    }

    cout << maxDist(0,to)+maxDist(n1+n2-1,to)+1 << endl;
    return 0;

}