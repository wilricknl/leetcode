class Solution {
public:
    int partitionArray(vector<int>& nums, int k)
    {
        std::sort(nums.begin(), nums.end());
        
        int value = nums[0];
        int answer = 1;
        for (int i = 1; i < nums.size(); ++i)
        {
            if (nums[i] - value > k)
            {
                value = nums[i];
                ++answer;
            }
        }
        return answer;
    }
};

