#include <bits/stdc++.h>
using namespace std;
int n,k;
int r[n];
int seq[n];
void solve(int lv){
    if(lv==n){
        int s=0;
        for(int i=0;i<n;++i)s+=seq[i];
        if(s%k == 0){
            for(int i=0;i<n;++i){
                cout << seq[i] << " ";
            }cout << enld;
        }
    }
    for(int i=1;i<=r[lv];++i){
        seq[lv] = i;
        solve(lv+1);
    }
}

int main(){
    cin >>n >> k;

    for(int i=0;i<n;++i){
        cin >> r[i];
    }

    solve(r);

}