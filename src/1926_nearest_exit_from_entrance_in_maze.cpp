class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        // empty cell: '.'
        // walls:      '+'
        std::vector<std::array<int, 2>> directions{
            { 0, -1 }, { 0, 1 }, { -1, 0 }, { 1, 0 }
        };
        int m = maze.size();
        int n = maze[0].size();

        int row = entrance[0];
        int column = entrance[1];

        std::queue<std::pair<int, int>> q;
        q.push({row, column});
        maze[row][column] = '+';

        int distance = 1;
        while (!q.empty())
        {
            int qs = q.size();

            for (int i = 0; i < qs; ++i)
            {
                auto [row, column] = q.front();
                q.pop();

                for (const auto& direction : directions)
                {
                    int nextRow = row + direction[0];
                    int nextColumn = column + direction[1];
                    // check for valid index
                    if (nextRow < 0 || nextRow >= m || nextColumn < 0 || nextColumn >= n)
                        continue;
                    // check for wall
                    if (maze[nextRow][nextColumn] == '+')
                        continue;
                    // check for exit
                    if (nextRow == 0 || nextRow == m - 1 || nextColumn == 0 || nextColumn == n -1)
                    {
                        return distance;
                    }
                    // add to queue
                    q.push({nextRow, nextColumn});
                    maze[nextRow][nextColumn] = '+';
                }
            }

            ++distance;
        }
        return -1;
    }
};

