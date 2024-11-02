#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;  cin >> n;
    vector<int>x(n);
    vector<int>p(n);
    vector<long long>sum(n+1);
    for(int i=0;i<n;++i){
        cin >> x.at(i);
    }
    sum[0] = 0;
    for(int i=0;i<n;++i){
        cin>> p.at(i);
        sum.at(i+1) = sum.at(i) + p.at(i);
    }

    int q;cin>>q;
    vector<long long> ans(q);
    for(int i=0;i<q;++i){
        int l,r;    cin >> l >> r;
        auto ll = upper_bound(x.begin(),x.end(),l-1)- x.begin();
        auto rr = upper_bound(x.begin(),x.end(),r)  - x.begin();
        ans.at(i) = (sum[rr]-sum[ll]);
    }
    for(int i=0;i<q;++i)cout<<ans.at(i)<<" ";
    cout << endl;
}