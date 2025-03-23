#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;  cin >> n;
    vector<long long> x(n);
    for(int i=0;i<n;i++)cin >> x[i];
    vector<long long> p(n);
    for(int i=0;i<n;++i)cin >> p[i];

    vector<long long> sum(n+1);
    
    for(int i=0;i<n;i++){
        sum[i+1] = sum[i] + p[i];
    }

    int q;  cin >> q;
    vector<long long> ans;
    for(int i=0;i<q;++i){
        int l,r;    cin >> l >> r;
        l--;
        auto ll = upper_bound(x.begin(),x.end(),l) - x.begin();
        auto rr = upper_bound(x.begin(),x.end(),r) - x.begin();
        ans.push_back(sum[rr]-sum[ll]);
    }
    for(auto a:ans)cout << a << "\n";
}