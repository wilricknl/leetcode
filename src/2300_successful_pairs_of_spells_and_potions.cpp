class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success)
    {
        std::sort(potions.begin(), potions.end());

        std::vector<int> answer;
        answer.reserve(spells.size());
        
        for (auto spell : spells)
        {
            int left = 0;
            int right = potions.size();
            while (left < right)
            {
                int middle = left + (right - left) / 2;
                long long product = 1LL * potions[middle] * spell;
                if (product >= success)
                {
                    right = middle;
                }
                else
                {
                    left = middle + 1;
                }
            }
            answer.push_back(potions.size() - left);
        }

        return answer;
    }
};

