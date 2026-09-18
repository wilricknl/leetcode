class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        long long total = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            total += nums[i];
        }
        
        int answer = 0;
        long long left = 0;
        for (int i = 0; i < nums.size() - 1; ++i)
        {
            left += nums[i];
            if (left >= total - left)
                ++answer;
        }
        
        return answer;
    }
};

