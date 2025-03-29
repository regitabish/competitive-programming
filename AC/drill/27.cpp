#include <bits/stdc++.h>
using namespace std;

vector<long long> divs(long long n){
    vector<long long> v;
    for(int i=1;i*i<=n;++i){
        if(n%i == 0){
            v.push_back(i);
            if(n/i != i){
                v.push_back(n/i);
            }
        }
        
    }
    return v;
}

int main(){
    long long n;
    cin>> n;
    vector<long long> a;
    map<long long,long long> mp;
    for(int i=0;i<n;i++){
        long long tmp;
        cin >> tmp;
        a.push_back(tmp);

        mp[tmp]++;
    }
    long long ans = 0;

    for(int i=0;i<n;i++){
        vector<long long> v = divs(a.at(i));
        for(auto div:v){
            ans += mp[div]*mp[a.at(i)/div];
        }
    }

    cout << ans << endl;


}