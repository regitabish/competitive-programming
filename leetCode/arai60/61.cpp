class KthLargest {
    priority_queue<int,vector<int>,greater<int>>pq;
    int k;
public:
    KthLargest(int k, vector<int>& nums):k(k) {
        for(auto num:nums)pq.push(num);
        while(pq.size()>k)pq.pop(); 
        return ; 
    }
    
    int add(int val) {
        pq.push(val);
        while(pq.size()>k)pq.pop();
        return pq.top();
    }

};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */