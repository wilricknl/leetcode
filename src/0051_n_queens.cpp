class Solution
{
public:
    std::unordered_set<int> columns;
    std::unordered_set<int> diagonals; // right to left
    std::unordered_set<int> diagonals2; // left to right
    int n;

    void backtrack(
        vector<vector<string>>& answer,
        int row,
        vector<string>& state)
    {
        if (row == n)
        {
            answer.push_back(state);
            return;
        }

        for (int column = 0; column < n; ++column)
        {
            if (columns.contains(column)
                || diagonals.contains(column - row)
                || diagonals2.contains(n - column - 1 - row))
                continue;

            columns.insert(column);
            diagonals.insert(column - row);
            diagonals2.insert(n - column - 1 - row);
            state[row][column] = 'Q';
            backtrack(answer, row + 1, state);
            state[row][column] = '.';
            diagonals2.erase(n - column - 1 - row);
            diagonals.erase(column - row);
            columns.erase(column);
        }
    }

    vector<vector<string>> solveNQueens(int n)
    {
        vector<vector<string>> answer;
        string row(n, '.');
        vector<string> state(n, row);

        columns.clear();
        diagonals.clear();
        diagonals2.clear();
        this->n = n;

        backtrack(answer, 0, state);
        return answer;
    }
};

