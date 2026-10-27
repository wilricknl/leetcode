class KthLargest {
public:
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for (auto num : nums)
        {
            add(num);
        }
    }
    
    int add(int val) {
        pq.push(val);
        if (pq.size() > k)
        {
            pq.pop();
        }
        return pq.top();
    }
        
private:
    std::priority_queue<int, std::vector<int>, std::greater<>> pq;
    int k;
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
 
