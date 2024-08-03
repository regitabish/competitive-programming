
#include <bits/stdc++.h>
using namespace std;

int main() {

    int n; cin >> n;

    vector<string> course;
    for(int i=0;i<n;i++){
        string tmp;
        cin >> tmp;
        course.push_back(tmp);
    }
    for(int i=1;i<n-1;i++){
        if(course[i-1] == course[i] && course[i] == "sweet"){
            cout << "No" << endl;
            return 0;
        }
    }

    cout << "Yes" << endl;

}
