class Solution {
public:
    void backtrack(
        std::vector<std::vector<int>>& answer,
        std::vector<int>& state,
        int index,
        int n,
        int k)
    {
        if (state.size() == k)
        {
            answer.push_back(state);
            return;
        }

        for (int i = index; i <= n; ++i)
        {
            state.push_back(i);
            backtrack(answer, state, i + 1, n, k);
            state.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k)
    {
        std::vector<std::vector<int>> answer;
        std::vector<int> state;
        backtrack(answer, state, 1, n, k);
        return answer;
    }
};

