#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m,h,k;
    cin >> n >> m >> h >> k;

    string s;   cin >> s;

    set<pair<int,int>> sp;

    for(int i=0;i<m;++i){
        int x,y;

        cin >> x >> y;
        sp.insert({x,y});
    }

    int nowx=0,nowy=0;

    for(int i=0;i<s.size();++i){
        if(s.at(i)=='R')nowx++;
        if(s.at(i)=='L')nowx--;
        if(s.at(i)=='U')nowy++;
        if(s.at(i)=='D')nowy--;

        h--;
        if(h<0){cout <<"No"<< endl; return 0;}

        if(sp.count({nowx,nowy}) && h<k){
            h=k;
            sp.erase({nowx,nowy});
        }

    }

    cout << "Yes" << endl;
}