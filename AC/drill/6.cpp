#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;

    int q;
    cin >> q;

    map<int, vector<int>> mp;

    vector<int> a;
    for(int i=0;i<n;++i){
        int tmp;
        cin >> tmp;
        a.push_back(tmp);

        mp[tmp].push_back(i+1);

    }

    for(int i=0;i<q;++i){
        int x,k;
        cin >> x >> k;

        if(k<=mp[x].size()){
            cout << mp[x].at(k-1) << endl;
        }else{
            cout << -1 << endl;
        }
    }


}