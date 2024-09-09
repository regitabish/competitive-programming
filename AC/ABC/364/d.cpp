
#include <bits/stdc++.h>
using namespace std;

struct grid{
    int ni;
    int nj;
};

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

        //ここ以下で二分探索で距離dを求める
        long long ok,ng;
        ok=0;
        ng=10e8;
        while(abs(ok-ng)>1){
            int dist;
            dist=(ok+ng)/2;
            if(isTherePointsThanKInD(dist)){
                //pointがK個以上あるので距離dは大きい。
                ng=dist;
            }else{
                ok=dist;
            }
        }

        ans.at(i)=ok;
    }

    for(int i=0;i<q;i++)cout << ans.at(i) << endl;
    return 0;

}