#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;  cin >>n;
    vector<int> x(n);
    for(int i=0;i<n;++i)cin>>x[i];
    vector<int> p(n);
    vector<long long> s(n+1);
    s[0] = 0;
    for(int i=0;i<n;++i){
        int tmp;    cin >> tmp;
        p[i] = tmp;
    } 
    for(int i=0;i<n;++i) s[i+1] = s[i] + p[i];

    int q;  cin >> q;
    vector<long long> ans;
    for(int i=0;i<q;++i){
        int l,r;    cin >> l >> r;
        auto ll = upper_bound(x.begin(),x.end(),l-1) - x.begin();
        auto rr = upper_bound(x.begin(),x.end(),r  ) - x.begin();
        ans.push_back(s[rr] - s[ll] );
    }
    for(int i=0;i<q;++i)cout << ans.at(i) << "\n";
    return 0;
}