#include<bits/stdc++.h>
using namespace std;

vector<long long> divs(const int  n){
    vector<long long> divs;
    for(int i=1;i*i<=n;++i){
        if(n%i==0){
            divs.push_back(i);
            if(n/i!=i){
                divs.push_back(n/i);
            }
        }
    }
    return divs;
}

int main(){
    int n;  cin >> n;
    vector<int> a;
    map<int,int>mp;
    for(int i=0;i<n;++i){
        int tmp;
        cin >> tmp;
        a.push_back(tmp);
        mp[tmp]++;
    }
    
    long long ans = 0;
    for(int i=0;i<n;i++){
        vector<long long> div;
        div = divs(a[i]);
        for(auto d:div){
            ans += 1LL* mp[d]*mp[a[i]/d];
        }
    }
    cout << ans << endl;
}