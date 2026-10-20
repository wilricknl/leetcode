class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        std::vector<std::vector<int>> graph(n);
        
        for (const auto& edge : edges)
        {
            int a = edge[0];
            int b = edge[1];
            graph[a].push_back(b);
            graph[b].push_back(a);
        }

        std::queue<int> q;
        std::vector<char> seen(n, false);
        
        q.push(source);
        seen[source] = true;

        while (!q.empty())
        {
            auto node = q.front();
            if (node == destination) return true;

            for (auto child : graph[node])
            {
                if (!seen[child])
                {
                    seen[child] = true;
                    q.push(child);
                }
            }

            q.pop();
        }

        return false;
    }
};

