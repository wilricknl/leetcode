class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int m = isWater.size();
        int n = isWater[0].size();
        int infinity = m * n;
        
        // top-right to bottom-left, look up and left
        for (int row = 0; row < m; ++row)
        {
            for (int column = 0; column < n; ++column)
            {
                if (isWater[row][column] == 1)
                {
                    isWater[row][column] = 0;
                    continue;
                }
                
                int best = infinity;
                if (row > 0)
                {
                    best = std::min(best, isWater[row - 1][column] + 1);
                }
                if (column > 0)
                {
                    best = std::min(best, isWater[row][column - 1] + 1);
                }

                isWater[row][column] = best;
            }
        }

        // bottom-left to top-right, look down and right
        for (int row = m - 1; row >= 0; --row)
        {
            for (int column = n - 1; column >= 0; --column)
            {
                if (isWater[row][column] == 0) continue;

                if (row < m - 1)
                {
                    isWater[row][column] = std::min(isWater[row][column], isWater[row + 1][column] + 1);
                }
                if (column < n - 1)
                {
                    isWater[row][column] = std::min(isWater[row][column], isWater[row][column + 1] + 1);
                }
            }
        }

        return isWater;
    }
};

