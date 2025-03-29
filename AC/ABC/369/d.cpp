#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;  cin >>n;
    vector<int> a(n+1,0);
    for(int i=1;i<=n;++i)cin >> a.at(i);

    vector<long long>dpEven(n+1,0);
    vector<long long>dpOdd(n+1,0);
    const long long  INF=1e10;

    dpEven[0] = 0;
    dpOdd[0] = -INF;

    int beatCount=0;
    for(int i=1;i<=n;i++){
        dpEven[i] = max(dpEven[i-1],dpOdd[i-1]+2*a[i]);
        dpOdd[i]  = max(dpOdd[i-1] ,dpEven[i-1]+a[i]);
    }

    cout << max(dpEven[n],dpOdd[n]) << endl;
    return 0;
}