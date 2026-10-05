class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        std::map<std::vector<int>, int> rowCount;

        int n = grid.size();
        for (int row = 0; row < n; ++row)
        {
            rowCount[grid[row]]++;
        }

        int answer = 0;
        std::vector<int> key(n);
        for (int column = 0; column < n; ++column)
        {           
            for (int row = 0; row < n; ++row)
            {
                key[row] = grid[row][column];
            }
            if (auto it = rowCount.find(key); it != rowCount.end())
            {
                answer += it->second;
            }
        }

        return answer;
    }
};

