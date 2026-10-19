class Solution {
public:
    int dfs(
        const std::vector<std::vector<std::pair<int, int>>>& graph,
        std::vector<char>& seen,
        int node)
    {
        if (seen[node]) return 0;

        int sum = 0;
        seen[node] = true;

        for (auto& [child, sign] : graph[node])
        {
            if (!seen[child])
            {
                sum += sign + dfs(graph, seen, child);
            }
        }

        return sum;
    }

    int minReorder(int n, vector<vector<int>>& connections)
    {
        // combination of undirected and directed graph to speed up the algorithm
        // .first is a connected node
        // .second = 1 means it was directed to .first, 0 means it was not directed
        // this avoids having to create a second directed graph
    
        std::vector<std::vector<std::pair<int, int>>> graph(n);
        std::vector<char> seen(n, false);
    
        for (const auto& connection : connections)
        {
            auto a = connection[0];
            auto b = connection[1];
            graph[a].push_back({b, 1});
            graph[b].push_back({a, 0});
        }

        return dfs(graph, seen, 0);
    }
};

