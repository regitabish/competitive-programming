#include<bits/stdc++.h>
using namespace std;

int main(){
    char c1,c2,c3;
    int a,b,c;
    cin >> c1 >> c2 >> c3;
    a = 0;
    if(c1 == '<' && c2 == '<' && c3 == '<')cout << 'B' << endl;
    if(c1 == '<' && c2 == '<' && c3 == '>')cout << 'C' << endl;
    if(c1 == '<' && c2 == '>' && c3 == '<')cout << 'A' << endl;
    if(c1 == '<' && c2 == '>' && c3 == '>')cout << 'A' << endl;
    if(c1 == '>' && c2 == '<' && c3 == '<')cout << 'A' << endl;
    if(c1 == '>' && c2 == '<' && c3 == '>')cout << 'A' << endl;
    if(c1 == '>' && c2 == '>' && c3 == '<')cout << 'C' << endl;
    if(c1 == '>' && c2 == '>' && c3 == '>')cout << 'B' << endl;

}

