#include<bits/stdc++.h>
using namespace std;

int main(){
    long long n,m;    cin >> n >> m;
    vector<long long> a(n);
    long long sum=0;
    for(int i=0;i<n;++i){
        cin >> a.at(i);
        sum+=a.at(i);
    }

    if(m>=sum){
        cout << "infinite" << endl;
        return 0;
    }

    long long ok=0,ng=10e14;

    while(abs(ok-ng)>1){
        long long mid = (ok+ng)/2;
        long long pay=0;
        for(int i=0;i<n;++i){
            pay+=min(a.at(i),mid);
        }

        if(pay>m){
            //payが大きすぎる
            ng=mid;
        }else{
            ok=mid;
        }
    }

    cout << ok << endl;

}