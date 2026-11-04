class Solution {
public:
    void backtrack(
        vector<vector<int>>& answer,
        int n,
        int k,
        vector<int>& state,
        int sum)
    {
        if (state.size() == k)
        {
            if (sum == n)
            {
                answer.push_back(state);
            }
            return;
        }

        if (sum >= n)
        {
            return;
        }

        for (int i = state.back() + 1; i <= 9; ++i)
        {
            state.push_back(i);
            backtrack(answer, n, k, state, sum + i);
            state.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n)
    {
        vector<vector<int>> answer;
        vector<int> state;
        for (int i = 1; i <= 9; ++i)
        {
            state.push_back(i);
            backtrack(answer, n, k, state, i);
            state.pop_back();
        }
        return answer;
    }
};

