#include<bits/stdc++.h>
using namespace std;
int n,k;    
int r[8] ;
int seq[8];

void solve(int lv){
    if(lv == n){//n桁そろっているなら出力
        int sum = 0;
        for(int i=0;i<n;++i){
            sum+= seq[i];
        }
        if(sum%k==0){
            for(int i=0;i<n;i++){
                cout << seq[i] << " ";
            }
            cout << endl;
        }
        return ;
    }

    //最終的に出力に使用するseqを作る
    //lv+1桁目を再帰的に呼び出す
    for(int i=1;i<=r[lv];i++){
        seq[lv] = i;
        solve(lv+1);
    }
}

int main(){

    cin >> n >> k;
    for(int i=0;i<n;i++){
        cin >> r[i];
    }
    solve(0);

    return 0;
}