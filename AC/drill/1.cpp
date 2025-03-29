//https://atcoder.jp/contests/adt_medium_20240813_1/editorial/3256

#include <bits/stdc++.h>
using namespace std;

int main() {

    int n;
    cin >> n;

    int q;
    cin >> q;

    int a[n];
    map<long long, vector<long long>> mp;
    for(int i=0;i<n;i++){
        cin >> a[i];
        mp[a[i]].push_back(i+1);
    }

    int x[q],k[q];
    for(int i=0;i<q;i++){
        cin >> x[i] >> k[i];
    }

    for(int i=0;i<q;i++){
        if(mp[x[i]].size()<k[i])cout << -1 << endl;
        else cout << mp[x[i]][k[i]-1] << endl;
    }


}
