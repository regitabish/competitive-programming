#include<bits/stdc++.h>
using namespace std;

vector<int> divs(int x){
    vector<int> ans;
    for(int i=1;i*i<=x;++i){
        if(x%i == 0){
            ans.push_back(i);
            if(i != x/i){
                ans.push_back(i);
            }
        }
    }
    return ans;
}

int main(){
    int n;  cin >> n;
    vector<int> a(n);
    map<int,int>mp;
    for(int i=0;i<n;++i){
        cin >> a.at(i);
        mp[a.at(i)]++;
    }
    long long ans = 0;
    for(int i=0;i<n;++i){
        int ai = a.at(i);
        for(auto aj:divs(ai)){
            int ak = ai/aj;
            ans += 1LL*mp[aj]*mp[ak];
        }
    }

    cout << ans << "\n";
    return 0;
}