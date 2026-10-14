class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        std::vector<int> answer;
        std::deque<int> d;
        
        int n = nums.size();
        for (int i = 0; i < n; ++i)
        {
            int value = nums[i];
            while (!d.empty() && value > nums[d.back()])
            {
                d.pop_back();
            }
            d.push_back(i);

            if (d.front() + k == i)
            {
                d.pop_front();
            }

            if (i >= k - 1)
            {
                answer.push_back(nums[d.front()]);
            }
        }
        
        return answer;
    }
};

