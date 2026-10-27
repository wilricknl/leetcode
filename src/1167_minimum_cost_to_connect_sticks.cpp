class Solution {
public:
    int connectSticks(vector<int>& sticks) {
        std::priority_queue<int, std::vector<int>, std::greater<>> pq(sticks.begin(), sticks.end());
        int total = 0;
        while (pq.size() > 1)
        {
            auto stick1 = pq.top();
            pq.pop();
            auto stick2 = pq.top();
            pq.pop();
            auto newStick = stick1 + stick2;
            total += newStick;
            pq.push(newStick);
        }
        return total;
    }
};

