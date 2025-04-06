class Solution {
public:
    bool canShip(vector<int>& weight, int days, int shipSize) {
        int neededDays = 1;
        int currSum = 0;
        for (auto w : weight) {
            if (shipSize < currSum + w) {
                neededDays++;
                currSum = w;
            } else {
                currSum += w;
            }
        }
        return days >= neededDays;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        // 答えで二分探索する
        int left = *max_element(weights.begin(),weights.end())
        int right = accumulate(weights.begin(),weights.end(),0);
        while (left < right) {
            int mid = left + (right - left) / 2;
            // コンテナサイズをmidとした場合に条件を満たせるか
            if (canShip(weights, days, mid)) {
                // このサイズではdays内で運べる
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};