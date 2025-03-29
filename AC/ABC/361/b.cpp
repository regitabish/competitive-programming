
#include <bits/stdc++.h>
using namespace std;

int main() {

    int a,b,c,d,e,f;
    int g,h,i,j,k,l;
    cin >> a >> b >> c >> d >> e >> f;
    cin >> g >> h >> i >> j >> k >> l;

    bool xflag,yflag,zflag;

    xflag = false;
    yflag = false;
    zflag = false;

    if( (g<a && a<j) || (g<d && d<j))xflag = true;
    if( (h<b && b<k) || (h<e && e<k))yflag = true;
    if( (i<c && c<l) || (i<f && f<l))zflag = true;

    if( (a<g && g<d) || (a<j && j<d))xflag = true;
    if( (b<h && h<e) || (b<k && k<e))yflag = true;
    if( (c<i && i<f) || (c<l && l<f))zflag = true;

    if(xflag && yflag && zflag){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }

}
