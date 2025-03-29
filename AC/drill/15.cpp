#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n,k;
    cin >>n>>k;

    vector<vector<int>> p(60,vector<int>(n+1));
    vector<int> a(n+1);
    for(int i=1;i<=n;++i)cin >> p[0][i];
    for(int i=1;i<=n;++i)cin >> a.at(i);

    for(int lv=1;lv<60;lv++){
        for(int i=1;i<=n;++i){
            p[lv][i] = p[lv-1][p[lv-1][i]];
        }
    }

    vector<long long> q(n+1);

    for(long long i=1;i<=n;++i)q[i]=i;

    for(int lv=0;lv<60;lv++){
        if(k%2==1){
        for(int i=1;i<=n;++i){            
                q[i]= p[lv][q[i]];   
            }
        }
        k/=2;
    }

    for(int i=1;i<=n;++i){
        if(i>=2)cout << " ";
        cout << a[q[i]];
    }
    cout << endl;
    return 0;

}