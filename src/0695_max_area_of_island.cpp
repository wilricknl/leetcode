class Solution {
public:
    int dfs(
        std::vector<std::vector<int>>& grid,
        int row,
        int column)
    {
        if (column < 0
            || column >= n
            || row < 0
            || row >= m
            || !grid[row][column])
        {
            return 0;
        }
        
        grid[row][column] = 0;
        
        return 1
            + dfs(grid, row, column - 1)
            + dfs(grid, row, column + 1)
            + dfs(grid, row - 1, column)
            + dfs(grid, row + 1, column);
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        
        int answer = 0;
        for (int row = 0; row < m; ++row)
        {
            for (int column = 0; column < n; ++column)
            {
                if (grid[row][column])
                {
                    answer = std::max(answer, dfs(grid, row, column));
                }
            }
        }
        return answer;
    }

private:
    int m;
    int n;
};

