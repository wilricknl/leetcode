#include <unordered_map>

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> matches;
        for (int i = 0; i < nums.size(); ++i)
        {
            auto value = nums[i];
            if (matches.count(target - value))
            {
                return {i, matches[target - value]};
            }
            matches[value] = i;
        }
        return {0, 0};
    }
};
