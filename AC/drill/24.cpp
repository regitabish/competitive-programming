#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;  cin >> n;
    string s;   cin >> s;

    vector<vector<int>> dp(n+1,vector<int>(3));

    for(int i=0;i<3;i++)dp[0][i]=0;

    for(int i=1;i<=n;++i){
        int x;
        if(s.at(i-1)=='R')x=0;
        if(s.at(i-1)=='P')x=1;
        if(s.at(i-1)=='S')x=2;
        
        for(int now=0;now<3;now++){
            int val=0;
            if((now+2)%3==x) val=1;  //勝ち
            if((now+1)%3==x) continue; //負け
            for(int prev=0;prev<3;prev++){
                if(now==prev)continue; //前回と同じ手
                dp[i][now]=max(dp[i][now],dp[i-1][prev]+val);
            }
        }
    }
    cout << max(dp[n][0],max(dp[n][1],dp[n][2])) << endl;

}