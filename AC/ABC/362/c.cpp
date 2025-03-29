#include <bits/stdc++.h>
using namespace std;

#include <atcoder/scc>
using namespace atcoder;

int main() {
    int n;
    cin >> n;

    vector<long> l(n);
    vector<long> r(n);
    long lSum,canIncrement;
    lSum = 0;
    canIncrement = 0;
    for (int i=0;i<n;i++){
        cin >> l.at(i) >> r.at(i);
        lSum += l.at(i);
        canIncrement += r.at(i) - l.at(i);


    }

    bool flag ;
    flag = false;

    if(lSum <= 0 && lSum + canIncrement >= 0 ){
        cout << "Yes" << endl;
        flag = true;
    }else{
        cout << "No" << endl;
        return 0;
    }

    long x ;
    x = lSum;

    for(int i=0;i<n;i++)        
    {
        long d; 
        d = min(r.at(i)-l.at(i),-x);
        x += d;
        l.at(i) += d;
        cout << l.at(i) << " ";
    }


}
