#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> h(n);

    for(int i=0;i<n;++i)cin >> h.at(i);

    long long t=0;
    for(int i=0;i<n;++i){
        int hp = h.at(i);

        int setT3 = hp/5;
        t+=setT3*3;

        hp-=setT3*5;

        while(hp>0){
            t+=1;
            if(t%3==0){
                hp-=3;
            }else{
                hp--;
            }
        }

    }
    cout << t << endl;
}