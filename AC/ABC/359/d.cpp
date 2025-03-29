
#include <bits/stdc++.h>
using namespace std;

int main() {

    long long n;
    cin >> n;

    vector<long long> h(n+1);
    for(long long i=1;i<=n;i++){
        cin >> h.at(i);
    }

    vector<long long> dp(n);

    dp.at(0)=0;
    dp.at(1)=h[1]+1;

    unordered_map<long long,long long> mp;
    vector<long long> tmpH(n+1);
    //cout << dp.at(1) << endl;
    long long maxH = 0;



    for(long long i=1;i<=n;i++){

        tmpH.push_back(h.at(i));
        
        mp[h.at(i)] = i;
        cout << h.at(i) << " " << i << endl;
        sort(tmpH.begin(),tmpH.end());
        
        //二分探索でtmpHのうちh[i]より高い壁の中で一番低いものの高さを特定
        long long Key = h[i];
        auto ite = lower_bound(tmpH.begin(),tmpH.end(),Key);
        long long Height = tmpH.at(distance(tmpH.begin(),ite)-1); 

        cout << Height <<endl;
        long long x = mp[Height];
        cout << x << endl;

        
        if(maxH<h.at(i))dp[i] = h.at(i)*i + 1;
        else dp[i] = dp[i-1] + (i-x)* Height +1 ;

        maxH = max(maxH,h.at(i));
    }

    for(long long i=1;i<=n;i++){
        cout << dp[i] << " "; 
    }
    cout << endl;
}
