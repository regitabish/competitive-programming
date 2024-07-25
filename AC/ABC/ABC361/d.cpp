
#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct node{
    ll space;
    ll step;
    string now;
}; 
unordered_map<string,bool>mp;
int main() {
    int n; cin >>n;
    string s;
    string t;
    cin >> s >> t;
    s = " " + s + "..";
    t = " " + t + "..";

    queue<node>q;

    q.push((node){n+1,0,s});

    mp[s] = true;

    while(!q.empty()){
        node u=q.front(); q.pop();
        //cout << u.now << endl;
        if(u.now == t){
            cout << u.step << endl;
            return 0;
        }
        for(int i=1;i<n+2;i++){
            
            if(i!=u.space && i!=u.space+1 && i!= u.space-1){
                string s = u.now;
                
                swap(s[u.space],s[i]);
                swap(s[u.space+1],s[i+1]);
                //cout << u.space << " " << s << endl;
                if(mp[s]==true)continue; //sが調べてあれば処理スキップ
                q.push((node){i,u.step+1,s});
                mp[s] = true;
            }
        }
    }

    cout << -1 << endl;

    return 0;

}
