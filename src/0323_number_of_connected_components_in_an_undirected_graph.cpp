class Solution {
public:
    int Find(std::vector<int>& parent, int a)
    {
        if (parent[a] != a)
        {
            parent[a] = Find(parent, parent[a]);
        }
        return parent[a];
    }

    bool Union(std::vector<int>& parent, std::vector<int>& rank, int a, int b)
    {
        auto rootA = Find(parent, a);
        auto rootB = Find(parent, b);
        
        if (rootA == rootB) return false;
        
        if (rank[rootA] < rank[rootB])
        {
            parent[rootA] = rootB;
        }
        else if (rank[rootA] > rank[rootB])
        {
            parent[rootB] = rootA;
        }
        else
        {
            parent[rootB] = rootA;
            ++rank[rootA];
        }

        return true;
    }

    int countComponents(int n, vector<vector<int>>& edges) {
        std::vector<int> parent(n);
        std::iota(parent.begin(), parent.end(), 0);
        std::vector<int> rank(n, 0);

        for (const auto& edge : edges)
        {
            Union(parent, rank, edge[0], edge[1]);
        }

        int answer = 0;
        for (int i = 0; i < n; ++i)
        {
            if (parent[i] == i)
                ++answer;
        }

        return answer;
    }
};

