//https://atcoder.jp/contests/adt_medium_20240813_1/editorial/6440

#include <bits/stdc++.h>
using namespace std;

struct now{
    int x;
    int y;
};

int main() {

    int n,m,k,h;
    cin >> n >> m >> k >> h;

    string s;
    cin >> s;
    set<pair<int, int>> st;
    int ix[m],iy[m];
    for(int i=0;i<m;i++){
        cin >> ix[m] >> iy[m];
        st.insert({ix[m],iy[m]});
    }


    now now = {0,0};

    for(auto c: s ){
        if(c=='R') now.x++;
        if(c=='l') now.x--;
        if(c=='U') now.y++;
        if(c=='D') now.y--;
        
        if(h<0){
            cout << "No" <<endl;
            return 0;
        }

        if(h<k && st.count({now.x,now.y})){
            h = k;
            st.erase({now.x,now.y});
        }

    }
}
