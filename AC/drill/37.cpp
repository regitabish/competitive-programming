#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    string s;
    cin >> s;

    vector<vector<int>>dp(3,vector<int>(n+1,-100000));

    for(int i=0;i<3;i++)dp[i][0]=0;

    for(int i=1;i<=n;i++){
        char c = s[i-1];
        int x;
        if(c=='R')x=0;
        if(c=='P')x=1;
        if(c=='S')x=2;
        //cout << "x=" << x << endl;
        for(int now=0;now<3;now++){
            //nowで今出す手を管理
            int val = 0;
            if((now+1)%3 == x)continue; //負け
            if((now+2)%3 == x) val = 1; //勝ち
            for(int prev=0;prev<3;prev++){
                //prevで直前の手を管理
                if(now==prev)continue;//直前と同じ手は出せない
                dp[now][i] = max(dp[now][i] ,dp[prev][i-1]+val);
            }
        }
    }
    cout << max(max(dp[0][n],dp[1][n]),dp[2][n]) << endl;
}