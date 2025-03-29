
#include <bits/stdc++.h>
using namespace std;

struct now{
    int x;
    int y; 
};

int main() {

    now now = {0,0};
    int n,m,h,k;
    cin >> n >> m >> h >> k;

    string s;
    cin >> s;

    pair<int,int> p[m];
    set<pair<int, int>> set;
    for(int i=0;i<m;i++){
        int tx,ty;
        cin >> tx >> ty;
        set.insert({tx,ty});
    }

    for(int i=0;i<s.size();i++){
        if(s.at(i) == 'R')now.x++;
        if(s.at(i) == 'L')now.x--;
        if(s.at(i) == 'U')now.y++;
        if(s.at(i) == 'D')now.y--;
        h--;
        if(h<0){
            cout << "No" << endl;
            return 0;
        }

        
        //cout << a.first << " " << a.second << endl;
        if(set.count({now.x,now.y}) && h<k){
            h=k;
            set.erase({now.x,now.y});
        }
        
    }

    cout << "Yes" << endl;
}
