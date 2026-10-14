class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        std::deque<int> increasing;
        std::deque<int> decreasing;
        int answer = 0;
        int left = 0;

        int n = nums.size();
        for (int right = 0; right < n; ++right)
        {
            int value = nums[right];
            while (!increasing.empty() && increasing.back() > value)
            {
                increasing.pop_back();
            }
            while (!decreasing.empty() && decreasing.back() < value)
            {
                decreasing.pop_back();
            }

            increasing.push_back(value);
            decreasing.push_back(value);

            while (decreasing.front() - increasing.front() > limit)
            {
                if (nums[left] == decreasing.front())
                {
                    decreasing.pop_front();
                }
                if (nums[left] == increasing.front())
                {
                    increasing.pop_front();
                }
                ++left;
            }

            answer = std::max(answer, right - left + 1);
        }

        return answer;
    }
};

