class Solution {
public:
    void backtrack(
        std::vector<std::vector<int>>& answer,
        std::vector<int>& state,
        int sum,
        std::vector<int>& candidates,
        int index,
        int target)
    {
        if (sum == target)
        {
            answer.push_back(state);
        }
        if (sum >= target || index == candidates.size())
        {
            return;
        }

        backtrack(answer, state, sum, candidates, index + 1, target);

        int value = candidates[index];
        int count = 0;
        while (sum + value <= target)
        {
            state.push_back(value);
            sum += value;
            ++count;
            backtrack(answer, state, sum, candidates, index + 1, target);
        }
        for (int i = 0; i < count; ++i)
            state.pop_back();
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        std::vector<std::vector<int>> answer;
        std::vector<int> state;
        backtrack(answer, state, 0, candidates, 0, target);
        return answer;
    }
};

