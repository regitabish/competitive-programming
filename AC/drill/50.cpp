#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,q;  cin >> n >> q;

    vector<int> a;
    for(int i=0;i<n;++i){
        int tmp;
        cin >> tmp;
        a.push_back(tmp);
    }

    sort(a.begin(),a.end());

    auto haveThanK = [&](int b, int k, long long d)->bool{
        auto r=upper_bound(a.begin(),a.end(),b+d);
        auto l=lower_bound(a.begin(),a.end(),b-d);

        return r-l>=k;
    };
    vector<int> ans;
    for(int i=0;i<q;i++){
        int b,k;    cin >> b >> k;
        long long l,r;
        l= -1;
        r= 1e10;
        long long d;
        while(abs(r-l)>1){
            d = (r+l)/2;
            if(haveThanK(b,k,d)){
                //距離dは大きい
                r=d;
            }else{
                l=d;
            }
        }
        //cout << d << "\n";
        ans.push_back(r);
    }

    for(auto answer:ans)cout<< answer << "\n";

}