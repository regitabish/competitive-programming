#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<int> a(n+1);
    for(int i=1;i<=n;++i)cin >> a.at(i);

    int dpo[n];
    int dpe[n];

    dpe[0] = 0;
    dpo[0] = -111;
    for(int i=1;i<=n;++i){
        dpo[i] = max(dpo[i-1],dpe[i-1]+a.at(i));
        dpe[i] = max(dpe[i-1],dpo[i-1]+2*a.at(i));

    }

    cout << max(dpo[n],dpe[n]) << endl;
    return 0;
}