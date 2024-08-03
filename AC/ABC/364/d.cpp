
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

    for(int i=0;i<q;i++){
        int b;  cin >> b;
        int k;  cin >> k;
        long long dl,dr,dkey;
        dl = 0;
        dr = 10e9;
        dkey = (dl+dr)/2;
        long long l,r;//左右それぞれの添え字

        while(1){
            l = upper_bound(a.begin(),a.end(),b-dkey) - a.begin();
            r = lower_bound(a.begin(),a.end(),b-dkey) - a.begin();
            //cout << l << " " << r << endl;
            if(r==l)break;
            if(r-l<k){
                //dが大きすぎる
                dkey=dr;
            }else{
                //dが小さい
                dkey=dl;
            }
        }

        cout << max(abs(a.at(r)-b),abs(b-a.at(l))) <<endl;
        
    }


}