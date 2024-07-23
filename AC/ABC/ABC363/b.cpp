
#include <bits/stdc++.h>
using namespace std;

int main() {

    int n,t,p;
    cin >> n >> t >> p;

    vector<int> l(n);
    for(int i=0;i<n;i++){
        cin >> l.at(i);
    }

    //p番目に髪の毛の長い人を特定
    sort(l.rbegin(),l.rend());

    int lp = l.at(p-1);
    
    if(t-lp > 0){
        cout << t - lp << endl;
    }else cout << 0 << endl;
}
