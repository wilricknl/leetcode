class Solution {
public:
    std::vector<std::pair<int, int>> organiseBoard(std::vector<std::vector<int>>& board, int n)
    {
        std::vector<std::pair<int, int>> graph;
        graph.reserve(n * n);

        bool bReverse = false;
        for (int row = n - 1; row >= 0; --row)
        {
            for (int c = 0; c < n; ++c)
            {
                int column = bReverse ? n - c - 1 : c;
                int value = board[row][column];
                if (value != -1) --value;
                graph.push_back({value, INT_MAX});
            }
            bReverse = !bReverse;
        }

        return graph;
    }

    int snakesAndLadders(vector<vector<int>>& board)
    {
        int n = board.size();
        int n_square = n * n;
        std::vector<std::pair<int, int>> graph = organiseBoard(board, n);

        std::queue<int> q;
        int distance = 0;
        q.push(0);
        graph[0].second = distance;

        while (!q.empty())
        {
            int qs = q.size();
            ++distance;

            for (int i = 0; i < qs; ++i)
            {
                auto node = q.front();
                q.pop();

                for (int dice = 1; dice < 7; ++dice)
                {
                    int nextNode = node + dice;

                    // outside playing field
                    if (nextNode >= n_square)
                        continue;

                    // check for snake or ladder
                    if (graph[nextNode].first != -1)
                    {
                        nextNode = graph[nextNode].first;
                    }

                    // skip if nextNode is already reached with less steps
                    if (graph[nextNode].second <= distance)
                        continue;

                    // save current distance
                    graph[nextNode].second = distance;

                    // win condition
                    if (nextNode == n_square - 1)
                    {
                        return distance;
                    }

                    q.push(nextNode);
                }
            }
        }

        return -1;
    }
};

