#include <bits/stdc++.h>
#include <iostream>
#include <array>
#include <algorithm>

using namespace std;
int main(){
    int n;  cin >> n;
    string s; cin >> s;

    bool drow;
    int ans = 0;
    const int INF = 1001100000;
    vector<vector<int>> dp(n+1,vector<int>(3,-INF));

    for(int i=0;i<3;++i)dp[0][i]=0;

    for(int i=1;i<=n;++i){
        //相手の出した手をxで管理
        int x=0;
        if(s[i-1]=='R')x=0;
        if(s[i-1]=='P')x=1;
        if(s[i-1]=='S')x=2;

        for(int j=0;j<3;j++){
            int val = 0;
            if(j == (x+1)%3) val = 1; //勝ち
            if(j == (x+2)%3) continue; //負ける手は出せない
            for(int pj=0;pj<3;pj++){
                //pj:直前に出した手
                if(j == pj)continue; //直前と同じ手は出せない
                dp[i][j] = max(dp[i][j],dp[i-1][pj]+val); //今現在でできている表の値と、直前までの点数と今出した手による得点の合計の大きいほうを採用
            }
        }
    }

    ans = max({dp[n][0],dp[n][1],dp[n][2]});
    cout << ans << endl;
    return 0;
}

