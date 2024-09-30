#include<bits/stdc++.h>
using namespace std;
vector<int> divs(int n){
    vector<int> ans;
    for(int i=2;i*i<=n){
        if(n%i == 0){
            ans.push_back(i);
            if(n/i != i){
                ans.push_back(n/i);
            }
        }
    }
    return ans;
}
int main(){
    int n,q;    cin >> n >> q;
    vector<int> a(n);
    for(int i=0;i<n;++i){
        cin >> a[i];

    }
    
}