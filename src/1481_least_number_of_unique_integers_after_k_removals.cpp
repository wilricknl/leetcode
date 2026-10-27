class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        std::unordered_map<int, int> count;
        for (auto num : arr)
        {
            count[num]++;
        }

        std::priority_queue<int, std::vector<int>, std::greater<>> pq;
        for (const auto& [key, value] : count)
        {
            pq.push(value);
        }

        while (true)
        {
            if (pq.empty() || pq.top() > k) break;

            k -= pq.top();
            pq.pop();
        }

        return pq.size();
    }
};

