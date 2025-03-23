#include<bits/stdc++.h>
using namespace std;

int n;
int k;

vector<int> r(8);
vector<int> ans(8);

void solve(int lv){
    if(lv == n){
        int sum = 0;
        for(int i=0;i<n;i++){
            sum += ans[i];
        }
        if(sum %k == 0){
            for(int i=0;i<n;i++){
                cout << ans[i] << " ";
            }cout << "\n";
            return ;
        }
    }
    for(int i=1;i<=r[lv];++i){
        ans[lv] = i;
        solve(lv+1);
    }
}

int main(){
    
    cin >> n >> k;
    for(int i=0;i<n;++i)cin >> r[i];
    solve(0);
}