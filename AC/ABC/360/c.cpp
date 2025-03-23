
#include <bits/stdc++.h>
using namespace std;

int main() {

    int n;
    cin >>n;

    vector<int> a(n),w(n);
    for(int i=0;i<n;i++)cin >> a.at(i);
    for(int i=0;i<n;i++)cin >> w.at(i);

    int ans ;
    ans = 0;
    map<int,int> mp;
    for(int i=0;i<n;i++){
        if(mp[a.at(i)] !=0){
            //既に存在
            ans += min(mp[a.at(i)],w.at(i));
            mp[a.at(i)] = max(mp[a.at(i)],w.at(i));
        }else{
            mp[a.at(i)] = w.at(i);
        }
    }

    cout << ans << endl;
}
