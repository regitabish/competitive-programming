class Solution {
    public:
        int coinChange(vector<int>& coins, int amount) {
            vector<int> dp(amount + 1,
                           INT_MAX - 10); // ある金額を作るのに最小のコインの枚数
            unordered_set<int> coinSet(coins.begin(), coins.end());
            dp[0] = 0; // 0円は0枚のコインで作れる
            for (int i = 1; i <= amount; ++i) {
                for (auto c : coins) {
                    if (i - c >= 0) {
                        dp[i] = min(dp[i], dp[i - c] + 1);
                    }
                }
            }
            if (dp[amount] == INT_MAX - 10)
                return -1;
            return dp[amount];
        }
    };