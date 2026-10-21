class Solution {
public:
    struct PathNode
    {
        int row;
        int column;
        int steps;
    };
    int shortestPathBinaryMatrix(vector<vector<int>>& grid)
    {
        if (grid[0][0]) return -1;

        std::vector<std::pair<int, int>> directions{
            { -1, -1 }, { -1, 0 }, { -1, 1 },
            { 0, -1 }, { 0, 1 },
            { 1, -1 }, { 1, 0 }, { 1, 1 }
        };
        int n = grid.size();
        std::queue<PathNode> q;
        q.push({0, 0, 1});
        grid[0][0] = 1;

        while (!q.empty())
        {
            auto node = q.front();
            q.pop();

            if (node.row == n - 1 && node.column == n - 1)
            {
                return node.steps;
            }

            for (const auto& direction : directions)
            {
                int nextRow = node.row + direction.first;
                int nextColumn = node.column + direction.second;
                if (nextRow >= 0
                    && nextRow < n
                    && nextColumn >= 0
                    && nextColumn < n
                    && grid[nextRow][nextColumn] == 0)
                {
                    grid[nextRow][nextColumn] = 1;
                    q.push({nextRow, nextColumn, node.steps + 1});
                }
            }
        }

        return -1;
    }
};

