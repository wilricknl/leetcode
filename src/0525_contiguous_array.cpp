class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        std::unordered_map<int, int> counts; // count to first index
        counts[0] = -1; // base case

        int answer = 0;
        int count = 0;

        for (int i = 0; i < nums.size(); ++i)
        {
            count += (nums[i] == 1 ? 1 : -1);
            if (counts.contains(count))
            {
                answer = std::max(answer, i - counts[count]);
            }
            else
            {
                counts[count] = i;
            }
        }

        return answer;
    }
};

