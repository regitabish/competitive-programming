#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;

    string s;
    cin >> s;

    const int INF=10000110;
    //dp[i][j];i回目にある手jを出した時の最大勝ち数
    vector<vector<int>> dp(n+1,vector<int>(3,-INF));

    for(int i=0;i<3;++i)dp[0][i]=0;

    for(int i=1;i<=n;i++){
        int x;
        if(s.at(i-1)=='R')x=0;
        if(s.at(i-1)=='P')x=1;
        if(s.at(i-1)=='S')x=2;

        for(int j=0;j<3;++j){
            int val=0;
            if(j==(x+1)%3)val=1;//勝ち
            if(j==(x+2)%3)continue;//負け
            for(int prev=0;prev<3;prev++){
                if(j==prev)continue;//直前と同じ手出せない
                //これより前でvalで勝敗を管理しておけば、ここで勝敗のif分の分岐書く必要ない
                dp[i][j]=max(dp[i][j],dp[i-1][prev]+val);
            }
            
        }
    }

    cout << max(dp[n][0],max(dp[n][1],dp[n][2])) << endl;
    return 0;
}