#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,q;    cin >> n >> q;
    vector<int> a;
    for(int i=0;i<n;i++){
        int tmp;
        cin >> tmp;
        a.push_back(tmp);
    }
    sort(a.begin(),a.end());

    auto checkDist = [&](int d,int k,int b)->bool{
        int lb=lower_bound(a.begin(),a.end(),b-d) - a.begin();
        int ub=upper_bound(a.begin(),a.end(),b+d) - a.begin();

        return ub-lb>=k;
    };

    for(int i=0;i<q;++i){
        int b,k;
        cin >> b >> k;

        int ok=0,ng=10e8;
        while(ng-ok>1){
            
            int mid = (ok+ng)/2;
            if(checkDist(mid,k,b)==true){
                //距離が短い
                ok=mid;
            }else{
                ng=mid;
            }
        }
    }
}