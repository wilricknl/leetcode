class Solution {
public:
    bool areOccurrencesEqual(string s) {
        std::array<int, 26> counts{};
        
        for (char letter : s)
        {
            ++counts[letter - 'a'];
        }

        int k = counts[s[0] - 'a'];
        for (int i = 0; i < 26; ++i)
        {
            if (counts[i] != 0 && counts[i] != k)
                return false;
        }

        return true;
    }
};

