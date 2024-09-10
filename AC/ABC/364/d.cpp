
#include <bits/stdc++.h>
using namespace std;
int main() {

    long long n,q;  cin >> n >> q;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin >> a.at(i);
    }

    sort(a.begin(),a.end());
    vector<int> ans(q,-1);

    for(int i=0;i<q;i++){
        int b;  cin >> b;
        int k;  cin >> k;

        auto isTherePointsThanKInD = [&](int d)->bool{
            //ある距離dを与えて区間[b-d,b-d]にaの点がK個以上あるかを判定するlambda式
            auto r=upper_bound(a.begin(),a.end(),b+d);
            auto l=lower_bound(a.begin(),a.end(),b-d);
            return r-l>=k;
        };

        //二分探索で距離dを決定->距離dが条件を満たすかの判定を二分探索
        long long ok,ng;
        ng=-1;
        ok=10e8;
        while(abs(ok-ng)>1){
            int dist;
            dist=(ok+ng)/2;
            if(isTherePointsThanKInD(dist)){
                //pointがK個よりもあるので距離dは大きい。
                ok=dist;
            }else{
                ng=dist;
            }
        }

        ans.at(i)=ok;
    }

    for(int i=0;i<q;i++)cout << ans.at(i) << endl;
    return 0;

}