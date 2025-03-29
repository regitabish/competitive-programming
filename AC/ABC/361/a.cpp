
#include <bits/stdc++.h>
using namespace std;

int main() {

    int n,k,x;
    cin >> n >> k >> x;
    vector<int> a(n+1);

    for(int i=1;i<=n;i++){
        cin >> a.at(i);
    }

    for(int i=1;i<=n;i++){
        
        cout << a.at(i) << " ";
        if(i == k)cout << x << " ";
    }     

}
