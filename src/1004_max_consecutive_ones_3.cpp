class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left = 0;
        int curr = 0;
        int answer = 0;

        for (int right = 0; right < nums.size(); ++right)
        {
           if (nums[right] == 0) ++curr;

            while (curr > k)
            {
                if (nums[left] == 0) --curr;
                ++left;
            }

            answer = std::max(answer, right - left + 1);
        }

        return answer;
    }
};

