
#include <bits/stdc++.h>
using namespace std;

int main() {

    int r,c;cin >> r >>c;

    char a[r][c];
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin >> a[i][j];
        }
    }

    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(a[i][j] != '.' && a[i][j] != '#'){
                
                int d = int(a[i][j] - '0');
               // cout << a[i][j] <<" "<<  d << endl;

                for(int k=0;k<r;k++){
                    for(int l=0;l<c;l++){
                        if(a[k][l]=='#' && abs(i-k) + abs(j-l) <= d){
                            a[k][l] = '.';
                            //cout << k << " " << l << endl;
                        }
                    }
                }

            }
        }
    }
    //cout << endl;

    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(a[i][j] != '.' && a[i][j] != '#'){
                a[i][j] = '.';
            }
            cout<< a[i][j];
        }
        cout << endl;
    }
}
