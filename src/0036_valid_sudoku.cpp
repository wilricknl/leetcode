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
};

