#include<bits/stdc++.h>
using namespace std;

int h,w;
const int INF=1e8;
vector<vector<int>> dist(h,vector<int>(w,INF));
vector<vector<bool>> select(h,vector<bool>(w,false));


void dfs(vector<vector<char>>field,pair<int, int> now, pair<int,int> prev={-1,-1}){
    
    dist[0].at(0) = 0;
    h=field.size();
    w=field[0].size();

    const string s = "snuke";
    
    int nowy=now.first;
    int nowx=now.second;

    if(nowy != 0 && nowx != 0){
        int prevy=prev.first;
        int prevx=prev.second;
        dist[nowy][nowx] = dist[prevy][prevx] + 1;
    }

    if(s.at(dist[nowy][nowx]%5) == field[nowy][nowx] ){
        &select[nowy][nowx] = true;
        if(nowy-1>=0) dfs(field,{nowy-1,nowx},{nowy,nowx});
        if(nowy+1<h)  dfs(field,{nowy+1,nowx},{nowy,nowx});
        if(nowx-1>=0) dfs(field,{nowy,nowx-1},{nowy,nowx});
        if(nowx+1<w)  dfs(field,{nowy,nowx+1},{nowy,nowx});
    }

}

int main(){
    int h,w;
    cin >> h >> w;

    vector<string> s(h);
    for(int i=0;i<h;i++){
        cin >> s.at(i);
    }

    vector<vector<char>>field(h,vector<char>(w));
    for(int i=0;i<h;++i){
        for(int j=0;j<w;j++){
            field[i][j] = s[i][j];
        }
    }




}