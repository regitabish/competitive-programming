#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;  cin >> n;
    vector<int> a(n+1);
    const int N = 2e5+10;
    const long long INF = 2e18;
    long long dpOdd[N];
    long long dpEve[N];
    dpOdd[0] =-(INF);
    dpEve[0] =0;

    for(int i=1;i<=n;++i){
        int tmp;    cin >> tmp;
        a.at(i) = tmp;
    }

    for(int i=1;i<n+1;++i){
        dpOdd[i] = max(dpEve[i-1]+a[i],  dpOdd[i-1]);
        dpEve[i] = max(dpOdd[i-1]+2*a[i],dpEve[i-1]);
    }
    cout << max(dpOdd[n],dpEve[n]) << endl;
    return 0;
}