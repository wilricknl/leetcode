class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        std::vector<std::pair<int, int>> directions{
            { 0, -1 }, { 0, 1 }, { -1, 0 }, { 1, 0}
        };
        int m = mat.size();
        int n = mat[0].size();

        std::vector<std::vector<int>> answer(m, std::vector<int>(n, 0));
        std::queue<std::pair<int, int>> q;

        for (int row = 0; row < m; ++row)
        {
            for (int column = 0; column < n; ++column)
            {
                if (mat[row][column] == 0)
                {
                    q.push({row, column});
                    mat[row][column] = -1;
                }
            }
        }

        int distance = 1;
        while (!q.empty())
        {
            int qsize = q.size();

            for (int i = 0; i < qsize; ++i)
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
                        && mat[nextRow][nextColumn] == 1)
                    {
                        q.push({nextRow, nextColumn});
                        answer[nextRow][nextColumn] = distance;
                        mat[nextRow][nextColumn] = -1;
                    }
                }
            }

            ++distance;
        }

        return answer;
    }
};

