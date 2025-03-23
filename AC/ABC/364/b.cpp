
#include <bits/stdc++.h>
using namespace std;

struct grid{
    int ni;
    int nj;
};

int main() {
    int h,w;
    cin >> h >> w;
    int si,sj;  cin >> si >> sj ;
    //si--;
    //sj--;

    char field[h+1][w+1];
    for(int i=1;i<=h;i++){
        for(int j=1;j<=w;j++){
            cin >> field[i][j];
        }
    }
    string s;   cin >> s;
    
    grid now = {si,sj};

    for(int i=0;i<s.size();i++){
        char direction;
        direction = s.at(i);
        //cout << direction << " " << now.ni << " " << now.nj ;
        
        if(direction == 'L' && field[now.ni][now.nj-1]=='.' && now.nj-1 > 0 ){
            now.nj = now.nj - 1;
        }
        if(direction == 'R' && field[now.ni][now.nj+1]=='.' && now.nj+1 <= w ){
            now.nj = now.nj + 1;
        }
        if(direction == 'U' && field[now.ni-1][now.nj]=='.' && now.ni-1 > 0 ){
            now.ni = now.ni - 1;
        }
        if(direction == 'D' && field[now.ni+1][now.nj]=='.' && now.ni+1 <= h ){
            now.ni = now.ni + 1;
        }
       // cout <<  " →" << now.ni << " " << now.nj << endl;
    }

    cout << now.ni  << " " << now.nj  << endl;

}
