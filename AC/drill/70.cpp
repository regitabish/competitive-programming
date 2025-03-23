#include<bits/stdc++.h>
using namespace std;
vector<long long> divs(long long n){
    vector<long long> ans;
    for(int i=1;i*i<=n;++i){
        if(n%i == 0){
            ans.push_back(i);
            if(n/i != i){
                ans.push_back(n/i);
            }
        }
    }
    return ans;
}
int main(){
    int n;    cin >> n ;
    vector<long long> a(n);
    map<int,int>mp;
    for(int i=0;i<n;++i){
        cin >> a[i];
        mp[a[i]]++;
    }
    long long ans = 0;
    //cout << 9999999999 <<endl;
    for(int i=0;i<n;++i){
        long long ai = a.at(i);
        vector<long long> v = divs(ai);
        //mp[a[i]]--;
        for(auto aj:v){
            ans+=1LL*mp[aj]*mp[ai/aj];
        }
        //mp[a[i]]++;
    }

    cout << ans << endl;

}