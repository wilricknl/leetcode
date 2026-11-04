class Solution {
public:
    void backtrack(
        vector<int>& answer,
        int n,
        int k,
        int state,
        int index)
    {
        if (index == n)
        {
            answer.push_back(state);
            return;
        }

        int digit = state % 10;
        
        if (digit - k >= 0)
        {
            backtrack(answer, n, k, state * 10 + digit - k, index + 1);
        }

        if (digit + k <= 9 && k != 0)
        {
            backtrack(answer, n, k, state * 10 + digit + k, index + 1);
        }
    }

    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int> answer;
        for (int i = 1; i <= 9; ++i)
        {
            backtrack(answer, n, k, i, 1);
        }
        return answer;
    }
};

