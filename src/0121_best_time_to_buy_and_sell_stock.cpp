class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minimum = prices[0];
        int maximum = minimum;
        int answer = 0;

        for (auto price : prices)
        {
            if (price < minimum)
            {
                minimum = price;
                maximum = price;
            }
            else
            {
                maximum = std::max(maximum, price);
                answer = std::max(answer, maximum - minimum);
            }
        }

        return answer;
    }
};

