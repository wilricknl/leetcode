class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        long long total = 0;
        int n = nums.size();
        int windowSize = 2 * k + 1;
        vector<int> answer(nums.size(), -1);
        
        if (windowSize > n) return answer;

        for (int i = 0; i < windowSize - 1; ++i)
        {
            total += nums[i];
        }

        
        for (int i = k; i < n - k; ++i)
        {
            total += nums[i+k];
            answer[i] = total / windowSize;
            total -= nums[i - k];
        }
        
        return answer;
    }
};

