class Solution {
public:
    void backtrack(
        std::vector<std::vector<int>>& answer,
        std::vector<int>& nums,
        int index,
        std::vector<int>& state)
    {
        if (index == nums.size())
        {
            answer.push_back(state);
            return;
        }

        backtrack(answer, nums, index + 1, state);
        
        state.push_back(nums[index]);
        backtrack(answer, nums, index + 1, state);
        state.pop_back();
    }

    vector<vector<int>> subsets(vector<int>& nums)
    {
        std::vector<std::vector<int>> answer;
        std::vector<int> state;
        backtrack(answer, nums, 0, state);
        return answer;    
    }
};

