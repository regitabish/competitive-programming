#include<bits/stdc++.h>
using namespace std;

int n,k;    
int r[10];
int ans[10];

void solve(int lv){
    for(int num = 1;num<=r[lv];num++){
        ans[lv] = num;

        if(lv == n-1){
            int sum = 0;
            for(int i=0;i<n;++i){
                sum += ans[i];
            }
            if(sum%k==0){
                for(int i=0;i<n;++i){
                    cout << ans[i] << " ";
                    if(i==n-1)cout << "\n";
                }
            }
        }else solve(lv+1);
    }

    return ;
}

int main(){
    cin >> n >> k;
    for(int i=0;i<n;++i)cin >> r[i];
    solve(0);
    return 0;
}