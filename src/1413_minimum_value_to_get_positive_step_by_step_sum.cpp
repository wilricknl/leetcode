class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int running_total = 0;
        int lowest = 0;

        for (auto num : nums)
        {
            running_total += num;
            lowest = std::min(lowest, running_total);
        }

        return 1 - lowest;
    }
};

