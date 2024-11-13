class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> prefix_sum_count;
        prefix_sum_count[0] =
            1; // 和がkになる部分配列を考慮するため、累積和0の出現回数を1として初期化
        int prefix_sum = 0;
        int count = 0;

        for (int num : nums) {
            prefix_sum += num; // 現在までの累積和を計算

            // prefix_sum - k
            // が過去に出現していたら、それは和がkになる部分配列の存在を意味する
            if (prefix_sum_count.find(prefix_sum - k) !=
                prefix_sum_count.end()) {
                count += prefix_sum_count[prefix_sum - k];
            }

            // 現在の累積和をマップに追加
            prefix_sum_count[prefix_sum]++;
        }

        return count;
    }
};
