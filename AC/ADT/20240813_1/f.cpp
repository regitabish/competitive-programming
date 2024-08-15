
#include <bits/stdc++.h>
using namespace std;

int main(){

    long long n,q;    cin >> n >> q;

    map<long long, vector<int>>mp;
    long long a[n];
    for(int i=0;i<n;i++){
        cin >> a[i];
        mp[a[i]].push_back(i+1);
    }
    long long x[q],k[q];
    for(int i=0;i<q;i++){
        cin >> x[i] >> k[i];
    }

    for(int i=0;i<q;i++){
        if(mp[x[i]].size()>=k[i])cout << mp[x[i]][k[i]-1] << endl;
        else cout << -1 << endl; 
    }

}

