#include <bits/stdc++.h>
using namespace std;
int main(){
    long long n,m;    cin >> n >>m;
    vector<long long> a;
    int long long sum = 0;
    for(int i=0;i<n;++i){
        int tmp;
        cin >> tmp;
        a.push_back(tmp);
        sum+=tmp;
    }

    if(m>=sum){
        cout << "infinite" << endl;
        return 0;
    }

    long long ok=0,ng=10e15;
    while(ng-ok>1){
        long long mid = (ok+ng)/2;
        long long paySum = 0;
        for(int i=0;i<n;i++){
            paySum += min(mid,a[i]);
        }
        if(paySum>m){
            ng=mid;
        }else{
            ok=mid;
        }
    }
    cout << ok << endl;
    return 0;
}