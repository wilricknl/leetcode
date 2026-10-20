class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        std::vector<char> hasIncomingEdges(n, false);
        for (const auto& edge : edges)
        {
            hasIncomingEdges[edge[1]] = true;
        }

        std::vector<int> answer;
        answer.reserve(n);
        for (int i = 0; i < n; ++i)
        {
            if (!hasIncomingEdges[i])
            {
                answer.push_back(i);
            }
        }

        return answer;
    }
};

