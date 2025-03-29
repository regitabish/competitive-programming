#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;  cin >> n;
    string s;   cin >> s;
    vector<vector<int>> dp(3,vector<int>(n+1));
    for(int i=0;i<3;++i)dp[i][0] = 0;
    
    for(int i=1;i<=n;++i){
        int x;
        if(s.at(i-1)=='R')x=0;
        if(s.at(i-1)=='P')x=1;
        if(s.at(i-1)=='S')x=2;
        //cout << i << endl;
        for(int now=0;now<3;now++){
            if((x+2)%3==now)continue;//lose
            int val = 0;
            for(int prev=0;prev<3;prev++){
                if(now==prev)continue;//same hand
                if((x+1)%3 == now)val=1;
                dp[now][i] = max(dp[prev][i-1]+val,dp[now][i]);
            }
        }
    }

    cout << max(dp[0][n],max(dp[1][n],dp[2][n])) << endl;
}