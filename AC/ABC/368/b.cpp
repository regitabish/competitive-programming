#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;  cin >> n;

    vector<int> a;
    for(int i=0;i<n;++i){
        int tmp;
        cin >> tmp;
        a.push_back(tmp);
    }

    int ans = 0;
    while(1){
        int sum = 0;
        for(int i=0;i<n;i++){
            if(a.at(i)>0)sum++;
        }
        //cout<<sum<< endl;
        if(sum<=1){cout << ans << endl;return 0;}


        sort(a.begin(),a.end());
        reverse(a.begin(),a.end());

        a.at(0)--;
        a.at(1)--;
        ans++;
        
    }
}