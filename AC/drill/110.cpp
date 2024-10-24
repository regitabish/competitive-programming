#include<bits/stdc++.h>
using namespace std;
int main(){
    long long n,m;    cin>>n>>m;
    vector<long long> a(n);
    long long sum = 0;
    for(int i=0;i<n;++i){
        cin >> a.at(i);
        sum += a.at(i);
    }
    if(sum<=m){
        cout<<"infinite"<<endl;
        return 0;
    }
    long long ok = -1,ng = 1e18;
    long long paySum = 0;
    while(abs(ng-ok)>1){
        long long pay = (ok+ng)/2;
        paySum = 0;
        for(int i=0;i<n;++i){
            paySum += min(pay,a.at(i));
        }
        if(paySum>m){
            //払いすぎ
            ng = pay;
        }else{
            ok = pay;
        }

    }
    cout << ok << endl;
}