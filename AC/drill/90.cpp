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
    
    auto moreThanK = [&](int k, long long d,int b)->bool{
        auto ll = lower_bound(a.begin(),a.end(),b-d);
        cout << "ll: " << ll-a.begin() << endl;
        auto rr = upper_bound(a.begin(),a.end(),b+d);
        cout << "rr: " << rr-a.begin() << endl;
        return rr-ll>=k;
    };
    vector<int> ans;
    for(int i=0;i<q;++i){
        int b,k;    cin >> b >> k;
        long long l = -1;
        long long r = 1e8+10;
        while(abs(r-l)>1){
            long long d = (r+l)/2;
            if(moreThanK(k,d,b)){
                r = d;
            }else{
                l = d;
            }
        }
        ans.push_back(r);
    }
    for(auto a:ans)cout << a << "\n";
    return 0;
}