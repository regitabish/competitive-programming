#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;  cin >> n;
    long long m; cin >> m;


    vector<long long> a;
    long long sum=0;

    for(int i=0;i<n;i++){
        long long tmp;
        cin >> tmp;
        a.push_back(tmp);
        sum+=tmp;
    }

    if(sum<=m){
        cout<< "infinite" << endl;
        return 0;
    }

    long long ng = 1e15;
    long long ok = 0;
    while(abs(ok-ng)>1){
        long long key = (ok+ng)/2;
        long long pay = 0;

        for(int i=0;i<n;++i) pay+=min(a.at(i),key);
        if(pay<=m){
            //もっと払える
            ok = key;
        }else{
            ng = key;
        }
    }

    cout << ok << endl;
}