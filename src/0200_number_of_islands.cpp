
class Solution {
public:
    void dfs(
        const std::vector<std::vector<char>>& grid,
        std::vector<std::vector<bool>>& seen,
        int row,
        int column)
    {
        if (seen[row][column]) return;
        seen[row][column] = true;
        
        // left
        int nextRow = row;
        int nextColumn = column - 1;
        if (nextColumn >= 0 && grid[nextRow][nextColumn] == '1')
        {
            dfs(grid, seen, nextRow, nextColumn);
        }
        
        // right
        nextRow = row;
        nextColumn = column + 1;
        if (nextColumn < grid[0].size() && grid[nextRow][nextColumn] == '1')
        {
            dfs(grid, seen, nextRow, nextColumn);
        }
        
        // above
        nextRow = row - 1;
        nextColumn = column;
        if (nextRow >= 0 && grid[nextRow][nextColumn] == '1')
        {
            dfs(grid, seen, nextRow, nextColumn);
        }
        
        // below
        nextRow = row + 1;
        nextColumn = column;
        if (nextRow < grid.size() && grid[nextRow][nextColumn] == '1')
        {
            dfs(grid, seen, nextRow, nextColumn);
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int answer = 0;
        int m = grid.size();
        int n = grid[0].size();
        std::vector<std::vector<bool>> seen(m, std::vector<bool>(n, false));

        for (int row = 0; row < m; ++row)
        {
            for (int column = 0; column < n; ++column)
            {
                if (grid[row][column] == '0') continue;
                
                if (!seen[row][column])
                {
                    ++answer;
                    dfs(grid, seen, row, column);
                }
            }
        }

        return answer;
    }
};

