#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;

    vector<int> hv(n);
    for(int i=0;i<n;i++)cin>>hv.at(i);

    long long t=0;
    for(int i=0;i<n;++i){
        int hp=hv.at(i);

        t+=(hp/5)*3;
        hp%=5;

        while(hp>0){
            t++;
            if(t%3==0){
                hp-=3;
            }else{
                hp--;
            }

        }
    }
    cout << t << endl;
}