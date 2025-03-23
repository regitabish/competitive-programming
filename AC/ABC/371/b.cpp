#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin >> n >> m;
    map<int,int>mp;

    vector<string> ans;
    for(int i=0;i<m;i++){
        int tmp;
        char c;
        cin >> tmp >> c;
        if(c=='M' && mp[tmp] == 0){
            ans.push_back("Yes");
            mp[tmp] = mp[tmp]+1;
        }else{
            ans.push_back("No");
        }
    }
    for(auto a:ans)cout << a << endl;
    
    return 0;
}