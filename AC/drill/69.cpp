#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;  cin >> n;
    vector<int> x(n);
    for(int i=0;i<n;++i){
        cin >> x[i];
    }
    vector<int> p(n);
    for(int i=0;i<n;++i){
        cin >> p[i];
    }
    vector<long long> s(n+1);
    s[0] = 0;
    for(int i=0;i<n;i++){
        s[i+1] = s[i] + p[i];
    }
    int q;  cin >> q;
    vector<long long> ans(q);
    for(int i=0;i<q;++i){
        int l,r;    cin >> l >> r;
        l--;
        long long ll = upper_bound(x.begin(),x.end(),l) - x.begin();
        long long rr = upper_bound(x.begin(),x.end(),r) - x.begin();
        ans[i] = s[rr] - s[ll];
    }
    for(int i=0;i<q;++i)cout << ans[i] << "\n";
    return 0;
}