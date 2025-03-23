#include <bits/stdc++.h>
using namespace std;
int main(){
    int n; cin >> n;
    int h=0;
    long long t = 0;
    for(int i=0;i<n;i++){
        cin >> h;
        t+=(h/5)*3;
        h -= (h/5)*5;
        while(h>0){
            //cout << h << endl;
            t++;
            if(t%3==0)h-=3;
            else h-=1;
        }
    }
    cout << t << endl;
    return 0;
}