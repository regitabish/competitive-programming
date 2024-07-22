
#include <bits/stdc++.h>
using namespace std;

int main() {

    int n,k;    cin >> n >> k;
    vector<int> v;
    deque<int> dq;

    for(int i=0;i<n;i++){
        cin >> v.at(i);
    }

    sort(v.begin(),v.end());

    for(int i : v ){
        dq.push_back(i);
    }

    

}
