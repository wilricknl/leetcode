class Solution {
public:
    double bfs(const std::unordered_map<std::string, std::vector<std::pair<std::string, double>>>& graph,
            const std::string& source,
            const std::string& target)
    {
        if (!graph.contains(source) || !graph.contains(target)) return -1.0;
        if (source == target) return 1.0;

        std::queue<std::pair<std::string, double>> q;
        std::unordered_set<std::string> seen;
        q.push({ source, 1.0 });
        seen.insert(source);

        while (!q.empty())
        {
            auto node = q.front();
            q.pop();

            for (const auto& [child, weight] : graph.at(node.first))
            {
                if (child == target)
                    return node.second * weight;
                
                if (!seen.contains(child))
                {
                    q.push({child, node.second * weight});
                    seen.insert(child);
                }
            }
        }
        return -1.0;
    }

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries)
    {
        std::unordered_map<std::string, std::vector<std::pair<std::string, double>>> graph;
        for (int i = 0; i < equations.size(); ++i)
        {
            auto a = equations[i][0];
            auto b = equations[i][1];
            graph[a].push_back({b, values[i]});
            graph[b].push_back({a, 1.0 / values[i]});
        }

        std::vector<double> answer;
        for (const auto& query : queries)
        {
            answer.push_back(bfs(graph, query[0], query[1]));
        }
        return answer;
    }
};

