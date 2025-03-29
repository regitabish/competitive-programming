
#include <bits/stdc++.h>
using namespace std;

struct grid{
    int ni;
    int nj;
};

int main() {

     n,x,y;
    cin >> n >> x >> y;

    vector<int>a,b;
    for(int i=0;i<n;i++){
        int tmp;
        cin >> tmp ;
        a.push_back(tmp);
    }
    for(int i=0;i<n;i++){
        int tmp;
        cin >> tmp ;
        b.push_back(tmp);
    }
    sort(a.begin(),a.end());
    
    sort(b.begin(),b.end());
    reverse(a.begin(),a.end());
    reverse(b.begin(),b.end());
    long long sumA=0,sumB=0;
    long long countA = 0, countB = 0;
    for(int tmpa: a){
        sumA+=tmpa;
        countA++;
        if(sumA>x)  break;
    }
    for(int tmpb:b){
        sumB+=tmpb;
        countB++;
        if(sumB>y)  break;
    }

    cout << min(n,min(countA,countB)) << endl;

}