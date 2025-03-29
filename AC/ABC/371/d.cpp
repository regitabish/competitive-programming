#include<bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    vector<int> x(n);
    for(int i=0;i<n;i++)cin>>x[i];
    
    vector<long long> p(n);
    p[0] = 0;
    for(int i=0;i<n;i++){
        cin >> p[i];
    }
    vector<long long> s(n+1);
    for(int i=0;i<n;i++)s[i+1] = s[i] + p[i];
    int q;  cin >> q;

    auto f = [&](int r){
        int pos = upper_bound(x.begin(),x.end(),r) - x.begin();
        return s[pos];
    };

    vector<long long> ans(q);
    for(int i=0;i<q;++i){
        int l,r;
        cin >> l >> r;
        
        ans.at(i) = f(r)-f(l-1);
    }
    for(int i=0;i<q;i++)cout << ans[i] << "\n";
    return 0;

}