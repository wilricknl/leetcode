// slow solution reusing 36
class Solution {
public:
    bool isValidRow(vector<vector<char>>& board, int row)
    {
        std::array<bool, 9> seen{};
        for (auto digit : board[row])
        {
            if (digit == '.')
                continue;
            int index = digit - '1';
            if (seen[index])
                return false;
            seen[index] = true;
        }
        return true;
    }

    bool isValidColumn(vector<vector<char>>& board, int column)
    {
        std::array<bool, 9> seen{};
        for (const auto& row : board)
        {
            int index = row[column];
            if (index == '.')
                continue;
            index -= '1';
            if (seen[index])
                return false;
            seen[index] = true;
        }
        return true;
    }

    bool isValidGrid(vector<vector<char>>& board, int row, int column)
    {
        std::array<bool, 9> seen{};
        for (int i = 0; i < 3; ++i)
        {
            for (int j = 0; j < 3; ++j)
            {
                int index = board[i + row * 3][j + column * 3];
                if (index == '.')
                    continue;
                index -= '1';
                if (seen[index])
                    return false;
                seen[index] = true;
            }
        }
        return true;
    }

    bool isValidSudoku(vector<vector<char>>& board)
    {
        for (int i = 0; i < 9; ++i)
        {
            if (!isValidRow(board, i))
                return false;
            if (!isValidColumn(board, i))
                return false;
        }

        for (int i = 0; i < 3; ++i)
            for (int j = 0; j < 3; ++j)
                if (!isValidGrid(board, i, j))
                    return false;

        return true;
    }

    bool backtrack(vector<vector<char>>& board, int index)
    {
        if (index == 81)
            return true;

        int row = index / 9;
        int column = index % 9;

        if (board[row][column] != '.')
            return backtrack(board, index + 1);

        for (int digit = 0; digit < 9; ++digit)
        {
            board[row][column] = '1' + digit;
            if (isValidRow(board, row) && isValidColumn(board, column) && isValidGrid(board, row / 3, column / 3))
            {
                if (backtrack(board, index + 1))
                {
                    return true;
                }
            }
            board[row][column] = '.';
        }
        return false;
    }

    void solveSudoku(vector<vector<char>>& board)
    {
        backtrack(board, 0);
    }
};

