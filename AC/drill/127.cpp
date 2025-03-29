#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,q;    cin >> n >> q;
    vector<int> a;
    for(int i=0;i<n;++i){
        int tmp;    cin >> tmp;
        a.push_back(tmp);
    }
    sort(a.begin(),a.end());
    
    vector<long long> ans;
    for(int i=0;i<q;++i){
        int b,k; cin >> b >> k;
        auto checkPoint = [&](long long d)->bool {
            auto ll = lower_bound(a.begin(),a.end(),b-d);
            auto rr = upper_bound(a.begin(),a.end(),b+d);
            return rr-ll>=k;
        };
        long long ng = -1, ok = 2e8;
        while(abs(ok-ng)>1){
            long long d = (ok+ng)/2;
            if(checkPoint(d)){
                ok = d;
            }else{
                ng = d;
            }
        }

        ans.push_back(ok);

    }

    for(auto an:ans){
        cout << an << " ";
    }cout<<endl;

}