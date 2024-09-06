#include <bits/stdc++.h>

using namespace std;

int main(){
    int k,n;    cin >> n >> k;

    vector<int> a;
    for(int i=0;i<n;++i){
        int tmp ; cin >> tmp;

        a.push_back(tmp);

    }

    for(int i=n-k;i<n;++i){
        cout << a.at(i) << " ";
    }
    for(int i=0;i<=n-k-1;++i){
        cout << a.at(i) << " ";
    }

    cout << endl;
}