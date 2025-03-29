#include <bits/stdc++.h>
using namespace std;
int ans = 0;
int a[400010],pre[400010];
int n,m;
map<int,int> cnt;

int main(){
    
    cin >> n >> m;
    
    for(int i=1;i<=n;i++){
        cin >> a[i];
        pre[i] = (pre[i-1] + a[i])%m;
    }
    for(int i=n+1;i<=n*2;i++){
        pre[i] = (pre[i-1] + a[i-n])%m;
    }
    
    for(int i=1;i<=n;i++){
        cnt[pre[i]]++;
    }
    
    for(int i=n+1;i<=2*n;i++){
        cnt[pre[i-n]]--;
        ans+=cnt[pre[i]];
        cnt[pre[i]]++;
    }

    cout << ans << endl;

}