#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;  cin >> n;
    long long t=0;
    for(int i=0;i<n;i++){
        int h;  cin >> h;
        t+=(h/5)*3;
        h=(h%5);
        while(h>0){
            t++;
            if(t%3 == 0)h-=3;
            else h--;
        }
    }
    cout << t << endl;
}