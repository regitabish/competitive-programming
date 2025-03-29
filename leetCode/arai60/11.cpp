class KthLargest {
private:
    int tmp;

public:
    priority_queue<int,vector<int>,greater<int>> pq;
    KthLargest(int k, vector<int>& nums) : tmp(k) {
        for (auto n : nums) {
            pq.push(n);
            if (pq.size() > tmp) {
                pq.pop();
            }
        }
    }

    int add(int val) {
        pq.push(val);
        //cout << tmp << endl;
        if (pq.size() > tmp) {
            pq.pop();
        }
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */