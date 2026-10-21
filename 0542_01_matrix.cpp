class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat)
    {
        std::vector<std::pair<int, int>> directions{
            { 0, -1 }, { 0, 1 }, { -1, 0 }, { 1, 0}
        };
        int m = mat.size();
        int n = mat[0].size();

        std::queue<std::pair<int, int>> q;

        for (int row = 0; row < m; ++row)
        {
            for (int column = 0; column < n; ++column)
            {
                if (mat[row][column] == 0)
                {
                    q.push({row, column});
                }
                else
                {
                    mat[row][column] = INT_MAX;
                }
            }
        }

        while (!q.empty())
        {
            auto [row, column] = q.front();
            q.pop();

            for (const auto& direction : directions)
            {
                int nextRow = row + direction.first;
                int nextColumn = column + direction.second;
                if (nextRow >= 0
                    && nextRow < m
                    && nextColumn >= 0
                    && nextColumn < n
                    && mat[nextRow][nextColumn] == INT_MAX)
                {
                    q.push({nextRow, nextColumn});
                    mat[nextRow][nextColumn] = mat[row][column] + 1;
                }
            }
        }

        return mat;
    }
};

