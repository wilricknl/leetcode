class Solution {
public:
    constexpr static int BLUE = 0;
    constexpr static int RED = 1;

    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        if (n == 1) return { 0 };

        std::vector<std::vector<std::vector<int>>> graph(2, std::vector<std::vector<int>>(n));
        std::vector<std::vector<char>> seen(2, std::vector<char>(n, false));

        for (const auto& edge : redEdges)
        {
            graph[RED][edge[0]].push_back(edge[1]);
        }

        for (const auto& edge : blueEdges)
        {
            graph[BLUE][edge[0]].push_back(edge[1]);
        }

        std::vector<int> answer(n, -1);
        std::queue<std::pair<int, int>> q;
        q.push({0, RED});
        seen[RED][0] = true;
        q.push({0, BLUE});
        seen[BLUE][0] = true;

        int distance = 0;
        while (!q.empty())
        {
            int qs = q.size();
            for (int i = 0; i < qs; ++i)
            {
                auto [node, previousColor] = q.front();
                q.pop();

                if (answer[node] == -1)
                    answer[node] = distance;

                int nextColor = 1 - previousColor;
                for (int child : graph[nextColor][node])
                {
                    if (!seen[nextColor][child])
                    {
                        seen[nextColor][child] = true;
                        q.push({child, nextColor});
                    }
                }
            }

            ++distance;
        }

        return answer;
    }
};

