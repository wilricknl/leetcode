class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost)
    {
        if (cost.size() < 2) return 0;
        int parent1 = cost[0];
        int parent2 = cost[1];

        int n = cost.size();
        for (int i = 2; i < n; ++i)
        {
            int temp = std::min(parent1, parent2) + cost[i];
            parent1 = parent2;
            parent2 = temp;
        }
        return std::min(parent1, parent2);
    }
};

