class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights)
    {
        rows = heights.size();
        columns = heights[0].size();

        int left = 0;
        int right = 0;
        for (const auto& row : heights)
        {
            for (auto height : row)
            {
                right = std::max(right, height);
            }
        }

        while (left <= right)
        {
            int middle = left + (right - left) / 2;
            if (check(heights, middle))
            {
                right = middle - 1;
            }
            else
            {
                left = middle + 1;
            }
        }
        return left;
    }

    bool check(vector<vector<int>>& heights, int k)
    {
        std::vector<std::vector<char>> seen(rows, std::vector<char>(columns, false));
        std::queue<std::pair<int, int>> q;
        q.push({0, 0});
        seen[0][0] = true;

        while(!q.empty())
        {
            auto [row, column] = q.front();
            q.pop();

            if ((row == (rows - 1)) && (column == (columns - 1)))
            {
                return true;
            }

            for (const auto& direction : directions)
            {
                auto nextRow = row + direction.first;
                auto nextColumn = column + direction.second;

                if (nextRow < 0 || nextRow >= rows
                    || nextColumn < 0 || nextColumn >= columns
                    || seen[nextRow][nextColumn])
                {
                    continue;
                }

                if (std::abs(heights[row][column] - heights[nextRow][nextColumn]) > k)
                {
                    continue;
                }

                q.push({nextRow, nextColumn});
                seen[nextRow][nextColumn] = true;
            }
        }

        return false;
    }

private:
    std::vector<std::pair<int, int>> directions{
        { 0, -1}, { 0, 1 }, { -1, 0 }, { 1, 0 } 
    };
    int rows = 0;
    int columns = 0;
};

