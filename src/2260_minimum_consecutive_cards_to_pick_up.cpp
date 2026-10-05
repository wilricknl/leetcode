class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        static int previousIndex[1000001];
        std::fill(previousIndex, previousIndex + 1000001, -1);

        int answer = INT_MAX;
        int n = cards.size();
        
        for (int i = 0; i < n; ++i)
        {
            auto card = cards[i];
            auto& index = previousIndex[card];
            if (index != -1)
            {
                answer = std::min(answer, i - previousIndex[card] + 1);
            }

            previousIndex[card] = i;
        }

        return answer != INT_MAX ? answer : -1;
    }
};

