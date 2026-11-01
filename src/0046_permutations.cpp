class Solution {
public:
    void backtrack(
        std::vector<std::vector<int>>& answer,
        int index,
        std::vector<int>& nums)
    {
        if (index == nums.size())
        {
            answer.push_back(nums);
            return;
        }

        for (int i = index; i < nums.size(); ++i)
        {
            std::swap(nums[index], nums[i]);
            backtrack(answer, index + 1, nums);
            std::swap(nums[i], nums[index]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums)
    {
        std::vector<std::vector<int>> answer;
        backtrack(answer, 0, nums);
        return answer;
    }
};

