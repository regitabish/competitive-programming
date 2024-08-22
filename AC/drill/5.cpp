#include <bits/stdc++.h>
using namespace std;

struct now{
    int x,y;
};

int main(){
    int n,m,h,k;    cin >> n >> m >> h >> k;
    set<pair<int, int>> set;
    string s;   cin >>s;

    now now={0,0};

    for(int i=0;i<m;i++){
        int hx,hy;
        cin >> hx >> hy;
        set.insert({hx,hy});
    }

    for(auto c: s ){
        h--;
        if(c=='R')now.x++;
        if(c=='L')now.x--;
        if(c=='U')now.y++;
        if(c=='D')now.y--;

        if(h<0){
            cout << "No" << endl;
            return 0;
        }

        if(h<k && set.count({now.x,now.y})){
            h=k;
            set.erase({now.x,now.y});
        }
    }

    cout << "Yes" << endl;
}
