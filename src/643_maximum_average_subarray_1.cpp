class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int sum = 0;
        for (int i = 0; i < k; ++i)
        {
            sum += nums[i];
        }

        double answer = static_cast<double>(sum) / static_cast<double>(k);

        for (int i = k; i < nums.size(); ++i)
        {
            sum = sum + nums[i] - nums[i-k];
            answer = std::max(answer, static_cast<double>(sum) / static_cast<double>(k));
        }

        return answer;
    }
};

