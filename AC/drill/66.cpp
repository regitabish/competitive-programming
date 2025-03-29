#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m,h,k;
    cin >> n >> m >> h >> k;
    string s;
    cin >> s;
    set<pair<int,int>> item;
    for(int i=0;i<m;++i){
        int x,y;
        cin >> x >> y;
        item.insert({x,y});
    }
    int nowx=0,nowy=0;
    for(int i=0;i<n;i++){
        char c = s.at(i);
        h--;
        if(h<0){
            cout << "No" << endl;
            return 0;
        }
        if(c=='R')nowx++;
        if(c=='L')nowx--;
        if(c=='U')nowy++;
        if(c=='D')nowy--;

        if(item.count({nowx,nowy}) && h<k ){
            h=k;
            item.erase({nowx,nowy});
        }

    }
    cout << "Yes" << endl;
    return 0;
}