#include<bits/stdc++.h>
using namespace std;
int main(){
    long long t=0;
    long long n;
    cin >>n;
    vector<long long> hv;

    for(int i=0;i<n;++i){
        long long tmp;
        cin >>tmp;
        hv.push_back(tmp);

        
    }

    for(int i=0;i<n;++i){
        long long h;
        h= hv.at(i);

        int num = h/5;
        t+=num*3;

        h -= num*5;
        while(h>0){
            t+=1;
            if(t%3==0){
                h-=3;
            }else{
                h--;
            }
        }
    }
    cout << t <<endl;
    
}