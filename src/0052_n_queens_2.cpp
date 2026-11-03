// you can make it faster with arrays... or bitmasking
class Solution {
public:
    std::unordered_set<int> columns;
    std::unordered_set<int> diagonals; // right to left
    std::unordered_set<int> diagonals2; // left to right
    int answer;
    int n;

    void backtrack(int row)
    {
        if (row == n)
        {
            ++answer;
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
            backtrack(row + 1);
            diagonals2.erase(n - column - 1 - row);
            diagonals.erase(column - row);
            columns.erase(column);
        }
    }

    int totalNQueens(int n)
    {
        columns.clear();
        diagonals.clear();
        diagonals2.clear();
        answer = 0;
        this->n = n;

        backtrack(0);
        return answer;
    }
};

