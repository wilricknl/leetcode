class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        std::vector<int> answer(temperatures.size(), 0);
        std::vector<int> temperatureToIndex(101, 0);
        std::stack<int> s;

        for (int i = temperatures.size() - 1; i >= 0; --i)
        {
            int temperature = temperatures[i];

            // clean up monotonic stack
            while (!s.empty() && s.top() <= temperature)
            {
                s.pop();
            }

            // compute answer
            if (!s.empty())
            {
                answer[i] = temperatureToIndex[s.top()] - i;
            }

            // push current temperature and index mapping
            s.push(temperature);
            temperatureToIndex[temperature] = i;
        }

        return answer;
    }
};

