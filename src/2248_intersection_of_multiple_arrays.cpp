class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) {
        std::map<int, int> counts;
        for (const auto& numbers : nums)
        {
            for (const auto& number : numbers)
            {
                counts[number]++;
            }
        }

        std::vector<int> answer;
        int k = nums.size();
        for (const auto& [key, value] : counts)
        {
            if (value == k)
                answer.push_back(key);
        }

        return answer;
    }
};

