class Solution {
public:
    void backtrack(vector<string>& answer, string state, int open, int close)
    {
        if (close == 0 && open == 0)
        {
            answer.push_back(state);
            return;
        }
        
        if (open > 0)
        {
            backtrack(answer, state + "(", open - 1, close);
        }
        
        if (open < close)
        {
            backtrack(answer, state + ")", open, close - 1);
        }
    }
    
    vector<string> generateParenthesis(int n)
    {
        vector<string> answer;
        backtrack(answer, "", n, n);
        return answer;
    }
};

