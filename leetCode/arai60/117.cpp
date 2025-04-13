class Solution {
    public:
        vector<vector<int>> subsets(vector<int>& nums) {
            vector<vector<int>> res;
            int n = nums.size();
            for(int mask = 0;mask<(1<<n);mask++){
                vector<int> subSet;
                for(int i=0;i<n;i++){
                    if(mask&(1<<i)){
                        subSet.push_back(nums[i]);
                    }
                }
                res.push_back(subSet);
            }
            return res;
        }
    };