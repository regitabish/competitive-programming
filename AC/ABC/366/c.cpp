#include <bits/stdc++.h>

using namespace std;

int main(){
    int q;  cin >> q;
    vector<int>ans;
    map<int,int>mp;
    int kind=0;
    for(int i=0;i<q;i++){
        int x,tmp;
        cin >> x;

        if(x==1){
            cin >> tmp;
            mp[tmp]++;
            if(mp[tmp]==1)kind++;
        }else if(x==2){
            cin >> tmp;
            mp[tmp]--;
            if(mp[tmp]==0)kind--;
        }else if(x==3){

            ans.push_back(kind);
        }
    }

    for(auto a:ans)cout << a << endl;
}