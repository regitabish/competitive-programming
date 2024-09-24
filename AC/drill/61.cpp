#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;  cin >> n;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++){
        int tmp;    cin >> tmp;
        a[i] = (tmp);
    }
    vector<long long> dpOdd(n+1);
    vector<long long> dpEve(n+1);
    dpOdd[0] = -1e15;
    dpEve[0] = 0;
    for(int i=1;i<=n;i++){
        dpOdd[i] = max(dpOdd[i-1],dpEve[i-1]+   a[i]);
        dpEve[i] = max(dpEve[i-1],dpOdd[i-1]+ 2*a[i]);
    }
    cout << max(dpOdd[n],dpEve[n]) << endl;
}