#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin >> n >> m;
    vector<long long> a(n);
    int sum=0;
    for(int i=0;i<n;++i){
        int tmp;
        cin >> tmp;
        a.push_back(tmp);

        sum+=tmp;
    }

    if(sum<=m){
        cout << "infinite" << endl;
        return 0;
    }

    long long ok,ng;
    ok=0;
    ng=1e10;

    while(abs(ng-ok)>1){
        long long mid = (ok+ng)/2;

        int pay=0;
        for(int i=0;i<n;++i){
            pay+=min(mid,a.at(i));
        }
        if(pay>=m){
            //払えない
            ng=mid;
        }else{
            //can more money
            ok=mid;
        }
    }

    cout << ok << endl;
    return 0;


}