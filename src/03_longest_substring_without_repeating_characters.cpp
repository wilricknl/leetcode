class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxLength = 0;

        std::unordered_map<char, int> previousIndex;
        int start = 0;
        for (int i = 0; i < s.size(); ++i)
        {
            // check if previous occurence exists and is in current substring
            if (previousIndex.contains(s[i]) && previousIndex[s[i]] >= start)
            {
                // update max length with current substring
                maxLength = std::max(maxLength, i - start);

                // start next substring right after the previous occurance
                start = previousIndex[s[i]] + 1;
            }

            // store index of current character
            previousIndex[s[i]] = i;
        }

        // check the very last substring also
        return std::max(maxLength, static_cast<int>(s.size()) - start);
    }
};
