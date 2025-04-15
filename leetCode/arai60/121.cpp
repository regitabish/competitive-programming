class Solution {
    public:
        int rob(vector<int>& nums) {
            return max(doRob(0,nums.size()-1,nums),doRob(1,nums.size(),nums));
        }
        int doRob(int start,int end,vector<int>& nums){
            if(nums.size()==1)return nums[0];
            int prev1=0;
            int prev2=0;
            int now = 0;
    
            for(int i=start;i<end;i++){
                now = max(prev1,prev2+nums[i]);
                prev2 = prev1;
                prev1 = now;
            }
            return now;
        }
    };