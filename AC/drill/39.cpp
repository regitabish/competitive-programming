#include <bits/stdc++.h>
using namespace std;


//aは値渡しするとTLEになるので参照渡しするかグローバル変数で管理
bool isPointsThanK(long long b,long long d, long long k,vector<long long>& a){
    auto r = upper_bound(a.begin(),a.end(),b+d);
    auto l = lower_bound(a.begin(),a.end(),b-d);

    if(r-l>=k)return true;
    else return false;
}

int main(){
    int n,q;
    cin >> n >> q;
    vector<long long> a;
    for(int i=0;i<n;i++){
        int tmp;
        cin >> tmp;
        a.push_back(tmp);
    }

    sort(a.begin(),a.end());

    
    vector<long long> ans;
    for(int i=0;i<q;i++){
        long long ok = 10e14, ng = -1; 
        long long b,k;  cin >> b >> k;

        while(abs(ng-ok)>1){
            long long mid = (ok+ng)/2;
            if(isPointsThanK(b,mid,k,a)){
                ok = mid;
            }else{
                ng = mid;
            }
        }
        ans.push_back(ok);
    }

    for(auto a:ans)cout << a << endl;
}