#include <bits/stdc++.h>
using namespace std;

vector<long long> enum_divisors(long long N) {
    vector<long long> res;
    for (long long i = 1; i * i <= N; ++i) {
        if (N % i == 0) {
            res.push_back(i);
            // 重複しないならば i の相方である N/i も push
            if (N/i != i) res.push_back(N/i);
        }
    }
    // 小さい順に並び替える
    sort(res.begin(), res.end());
    return res;
}


int main(){
    int n;
    cin >> n;

    long long a[n];

    map<int, int> mp;
    for(int i=0;i<n;i++){
        cin>> a[i];
        mp[a[i]]++;
    }

    long long ans = 0;

    for(int i=0;i<n;i++){
        const auto &divs = enum_divisors(a[i]);
        for(auto div : divs){
            ans+=mp[div]  mp[a[i]/div];
        }
    }

    cout << ans << endl;


}