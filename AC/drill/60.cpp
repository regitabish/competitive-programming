#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,q;    cin >> n >> q;
    vector<int> a(n);
    for(int i=0;i<n;i++)cin >> a[i];
    sort(a.begin(),a.end());
    
    auto check = [&](long long d,int k,int b)->bool{
        auto r = lower_bound(a.begin(),a.end(),b+d);
        auto l = upper_bound(a.begin(),a.end(),b-d);

        return r-l>=k;
    };
    vector<int> ans;
    for(int i=0;i<q;i++){
        int b,k;    cin >> b >> k;
        long long ok = 0, ng = 1e18;
        while(abs(ng-ok)>1){
            long long d = (ok+ng)/2;
            if(check(d,k,b)){
                ng = d;
            }else{
                ok = d;
            }
        }
        ans.push_back(ok);
    }
    for(auto answer:ans) cout << answer << "\n";
}