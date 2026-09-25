class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        std::unordered_map<int, int> counts; // store how often a certain amount of odd numbers has been seen
        counts[0] = 1;
        int odd_numbers_seen = 0;
        int answer = 0;

        for (int i = 0; i < nums.size(); ++i)
        {
            odd_numbers_seen += nums[i] % 2;
            answer += counts[odd_numbers_seen - k];
            ++counts[odd_numbers_seen];
        }

        return answer;
    }
};

