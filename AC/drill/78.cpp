#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;  cin >> n;
    string s;   cin >> s;
    vector<vector<int>> dp(3,vector<int>(n+1,-10));
    for(int i=0;i<3;++i)dp[i][0] = 0;

    for(int i=1;i<=n;++i){
        char c = s.at(i-1);
        int x;
        if(c == 'R') x=0;
        if(c == 'S') x=1;
        if(c == 'P') x=2;
        for(int now=0;now<3;now++){
            int val = 0;
            if(now == (x+1)%3)continue;//lose
            if(now == (x+2)%3)val = 1; //win

            for(int pre=0;pre<3;pre++){
                if(now == pre)continue;
                dp[now][i] = max(dp[now][i], dp[pre][i-1] + val);
            }
        }


    }

    cout << max(dp[0][n],max(dp[1][n],dp[2][n])) << endl;
}