#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,q;    cin >> n >> q;
    vector<int> a(n);
    for(int i=0;i<n;++i){
        cin >> a[i];
    }
    sort(a.begin(),a.end());

    auto checkPointsThanK = [&](int k,int b, long long d)->bool{
        auto r = upper_bound(a.begin(),a.end(),b+d);
        auto l = lower_bound(a.begin(),a.end(),b-d);
        return r-l>=k;
    };
    vector<int> b(q);
    vector<int> k(q);

    for(int i=0;i<q;++i){cin >> b[i] >> k[i];}
        
    for(int i=0;i<q;++i){
        long long ok = 1e18,ng = -1;

        while(abs(ok-ng)>1){
            long long d = (ok+ng)/2;
            if(checkPointsThanK(k[i],b[i],d)){
                //D が大きい
                ok = d;
            }else{
                ng = d;
            }
        }
        cout << ok << "\n";
    }
    return 0;
}