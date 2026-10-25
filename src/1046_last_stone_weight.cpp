class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        std::priority_queue<int> pq(stones.begin(), stones.end());
        while (pq.size() > 1)
        {
            auto stone1 = pq.top();
            pq.pop();
            auto stone2 = pq.top();
            pq.pop();
            if (stone1 != stone2)
            {
                pq.push(std::abs(stone1 - stone2));
            }
        }
        return !pq.empty() ? pq.top() : 0;
    }
};

