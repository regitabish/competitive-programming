#include <iostream>
#include <vector>
#include <unordered_map>

#define MOD 998244353

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<long long> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    vector<long long> result(N, 0);  // 長さ k の等差部分列の個数
    vector<vector<unordered_map<long long, long long>>> dp(N, vector<unordered_map<long long, long long>>(N));
    result[0] = N;
    // 各要素について
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < i; ++j) {
            long long d = A[i] - A[j];
            dp[i][1][d] = (dp[i][1][d] + 1) % MOD;  // 長さ 2 の等差部分列
            for (int k = 1; k < N - 1; ++k) {
                dp[i][k + 1][d] = (dp[i][k + 1][d] + dp[j][k][d]) % MOD;
            }
        }
        for (int k = 1; k < N; ++k) {
            for (auto& p : dp[i][k]) {
                cout << p.first << " " << p.second << endl;
                result[k] = (result[k] + p.second) % MOD;
            }
        }
    }

    // 結果を出力
    for (int k = 1; k <= N; ++k) {
        cout << result[k - 1] << " ";
    }
    cout << endl;

    return 0;
}
