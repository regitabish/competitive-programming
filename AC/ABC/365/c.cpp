#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >>n;
    long long m;
    cin >>m;

    long long sum=0;
    vector<long long>a(n);
    for(int i=0;i<n;++i){
        cin >> a.at(i);
        sum+=a.at(i);
    }

    if(sum<=m){
        cout << "infinite" << endl;
        return 0;
    }

    long long ok=0,ng=1e10;

    while(abs(ok-ng)>1){
        long long mid = (ok+ng)/2;
        long long tmp = 0;

        for(auto v:a)tmp+=min(v,mid);

        if(tmp>m){
            ng = mid;
        }else{
            ok = mid;
        }
    }

    cout << ok << endl;

}