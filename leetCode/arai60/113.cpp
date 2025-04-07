class Solution {
    private:
        bool canShip(vector<int>& weights,const int days,const int mid){
            int neededDays = 1;
            int currentSum = 0;
            for(auto w:weights){
                if(mid<currentSum + w){
                    neededDays++;
                    currentSum = w;
                }else{
                    currentSum += w;
                }
            }
            return neededDays <= days;
        }
    public:
        int shipWithinDays(vector<int>& weights, int days) {
            int left = *max_element(weights.begin(),weights.end());
            int right = accumulate(weights.begin(),weights.end(),0);
            while(left<right){
                int mid = left + (right - left)/2;
                if(canShip(weights,days,mid)){
                    right = mid;
                }else{
                    left = mid + 1;
                }
            }
            return left;
        }
    };