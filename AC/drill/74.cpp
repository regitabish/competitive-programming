#include<bits/stdc++.h>
using namespace std;
vector<long long> divs(long long n){
    vector<long long> ans;
    for(int i=1;i<n;++i){
        if(n%i==0){
            ans.push_back(i);
            if(n/i != i){
                ans.push_back(n/i);
            }
        }
    }
    return ans;
}
int main(){
    int n,q;cin>> n>>q;
    vector<long long> a;
    map<long long,long long>mp;
    for(int i=0;i<n;++i){
        long long tmp;    cin >> tmp;
        mp[tmp]++;
        a.push_back(tmp);
    }

    long long ans = 0;
    for(int i=0;i<n;++i){
        long long ai = a.at(i);
        for(auto aj:divs(ai)){
            ans += 1LL*mp[aj]*mp[ai/aj];
        }
    }
    cout << ans << endl;
}