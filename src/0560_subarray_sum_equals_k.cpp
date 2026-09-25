class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        std::unordered_map<int, int> counts; // prefix sum counts
        counts[0] = 1; // needed for subarrays that start at 0

        int curr = 0;
        int answer = 0;
        for (auto num : nums)
        {
            curr += num;
            answer += counts[curr - k];
            ++counts[curr];
        }

        return answer;
    }
};

