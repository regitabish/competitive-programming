#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    long long T;
    cin >> N >> T;

    string S;
    cin >> S;

    vector<long long> X(N);
    for (int i = 0; i < N; ++i) {
        cin >> X[i];
    }

    vector<long long> rightMoving, leftMoving;

    // 蟻を分類
    for (int i = 0; i < N; ++i) {
        if (S[i] == '1') {
            rightMoving.push_back(X[i]);
        } else {
            leftMoving.push_back(X[i]);
        }
    }

    sort(rightMoving.begin(), rightMoving.end());
    sort(leftMoving.begin(), leftMoving.end());

    long long count = 0;
    int j = 0;

    // 尺取り法でのすれ違いのカウント
    for (int i = 0; i < rightMoving.size(); ++i) {
        
        while (j < leftMoving.size() && rightMoving[i] + 2*T >= leftMoving[j]) {
            cout << i << " " << j << endl;
            j++;
        }
        
        count += j;
    }

    cout << count << endl;

    return 0;
}
