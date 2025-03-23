#include<bits/stdc++.h>
using namespace std;

int main(){
    int m;  cin >> m;
    vector<int> ans;
    while(m>0){
        for(int i=0;i<=20;i++){
            long long tmp = pow(3,i);
            //cout << tmp << " " << m << endl;
            if(m<tmp){

                ans.push_back(i-1);
                m-=pow(3,i-1);
                break;
            }
        }
    }
    cout << ans.size() << endl;
    for(auto a:ans)cout << a << " ";
    cout << endl;
}