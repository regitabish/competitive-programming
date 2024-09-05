#include <bits/stdc++.h>
using namespace std;

vector<long long> div(int n){
    vector<long long> v;

    for(int i=1;i*i<=n;i++){
        if(n%i==0){
            v.push_back(i);
            //以下の条件分岐忘れないこと。
            if(i != n/i){
            v.push_back(n/i); 
            }
        }
    }

    return v;
}

int main(){
    long long n;
    cin >>n;
    map<long long,long long>mp;

    vector<long long> a;
    for(int i=0;i<n;++i){
        int tmp ;
        cin >> tmp;
        a.push_back(tmp);
        mp[tmp]++;
    }

    long long ans = 0;
    for(int i=0;i<n;++i){
        long long Ai = a.at(i);
        vector<long long> v = div(Ai);
        for(auto a: v){
            ans+=1LL*mp[a]*mp[Ai/a];
        }
    }
    cout << ans << endl;
}