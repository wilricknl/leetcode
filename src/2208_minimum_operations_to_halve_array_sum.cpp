class Solution {
public:
    int halveArray(vector<int>& nums) {
        if (nums.size() == 1) return 1;

        double sum = std::accumulate(nums.begin(), nums.end(), 0.0);
        std::priority_queue<double> pq(nums.begin(), nums.end());
        
        auto halfSum = sum / 2.0;
        int steps = 0;
        while (halfSum > 0.0)
        {
            ++steps;
            
            auto num = pq.top();
            pq.pop();
            
            auto halfNum = num / 2.0;
            halfSum -= halfNum;

            pq.push(halfNum);
        }

        return steps;
    }
};

