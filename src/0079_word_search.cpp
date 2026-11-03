class Solution {
public:
    vector<pair<int, int>> directions{
        { 0, -1 }, { 0, 1 }, { -1, 0 }, { 1, 0 }
    };
    int m;
    int n;

    bool backtrack(
        vector<vector<char>>& board,
        const string& target,
        int row,
        int column,
        int index)
    {
        if (index == target.size())
        {
            return true;
        }

        for (const auto& direction : directions)
        {
            int nextRow = row + direction.first;
            int nextColumn = column + direction.second;
            if (nextRow < 0 || nextRow >= m || nextColumn < 0 || nextColumn >= n)
                continue;
            
            if (board[nextRow][nextColumn] == target[index])
            {

                board[nextRow][nextColumn] = 0;
                if (backtrack(board, target, nextRow, nextColumn, index + 1))
                {
                    return true;
                }
                board[nextRow][nextColumn] = target[index];
            }
        }

        return false;
    }

    bool exist(vector<vector<char>>& board, string word)
    {
        m = board.size();
        n = board[0].size();

        for (int row = 0; row < m; ++row)
        {
            for (int column = 0; column < n; ++column)
            {
                if (board[row][column] != word[0])
                    continue;
                board[row][column] = 0;
                if (backtrack(board, word, row, column, 1))
                    return true;
                board[row][column] = word[0];
            }
        }

        return false;
    }
};

