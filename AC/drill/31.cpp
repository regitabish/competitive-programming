#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;  cin >> n;
    vector<long long> a(n+1,0);
    for(int i=1;i<=n;i++)cin >> a.at(i);

    vector<long long> dpOdd(n+1,0);
    vector<long long> dpEve(n+1,0);

    const long long INF = 10e10; //これが十分に大きい値でないとダメ
    dpOdd[0] = -INF;
    dpEve[0] = 0;

    for(int i=1;i<=n;i++){
        dpOdd[i] = max(dpOdd[i-1], dpEve[i-1] + a.at(i));
        dpEve[i] = max(dpEve[i-1], dpOdd[i-1] + 2*a.at(i));
    }

    cout << max(dpOdd[n],dpEve[n]) << endl;
    return 0;
}