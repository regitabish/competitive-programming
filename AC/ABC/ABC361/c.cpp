
#include <bits/stdc++.h>
using namespace std;

int main() {

    int n,k;    cin >> n >> k;
    vector<long long> v(n);

    for(int i=0;i<n;i++){
        cin >> v.at(i);
    }

    sort(v.begin(),v.end());

    long long ans ;
    ans = 2e9;

    for(int i=0;i<=k;i++){
        ans = min(ans,v.at(i+(n-k)-1)-v.at(i));
    }

    cout << ans << endl;
}
