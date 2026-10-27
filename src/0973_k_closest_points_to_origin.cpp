class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        std::priority_queue<std::pair<int, std::vector<int>>> pq;
        for (const auto& point : points)
        {
            pq.push({point[0] * point[0] + point[1] * point[1], point});
            if (pq.size() > k)
                pq.pop();
        }
        std::vector<std::vector<int>> answer;
        while(!pq.empty())
        {
            answer.push_back(pq.top().second);
            pq.pop();
        }
        return answer;
    }
};

