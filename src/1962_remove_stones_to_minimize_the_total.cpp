class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        int total = std::accumulate(piles.begin(), piles.end(), 0);
        std::priority_queue<int> pq(piles.begin(), piles.end());
        
        for (int i = 0; i < k; ++i)
        {
            auto value = pq.top();
            pq.pop();
            int floor = (int)std::floor(value / 2.0f);
            total -= floor;
            pq.push(value - floor);
        }
        
        return total;
    }
};

