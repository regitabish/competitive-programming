#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    long long m;
    cin >> n >> m;
    vector<long long> a;
    long long sum = 0;
    for(int i=0;i<n;++i){
        long long tmp;
        cin >> tmp;
        a.push_back(tmp);
        sum+=tmp;
    }
    if(sum<=m){
        cout << "infinite" << endl;
        return 0;
    }

    sort(a.begin(),a.end());
    long long ok = 0,ng = 1e18;
    while(ng-ok>1){
        long long mid = (ng+ok)/2;
        long long pay = 0;
        for(int i=0;i<n;++i){
            pay += min(a.at(i),mid);
        }
        if(pay>m){
            ng = mid;
        }else{
            ok = mid;
        }
    }
    cout << ok << endl;
    return 0;
}

