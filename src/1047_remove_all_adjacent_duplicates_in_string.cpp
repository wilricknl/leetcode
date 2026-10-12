class Solution {
public:
    string removeDuplicates(string s) {
        std::string result;
        result.reserve(s.size());
        for (char letter : s)
        {
            if (!result.empty() && result.back() == letter)
            {
                result.pop_back();
            }
            else
            {
                result.push_back(letter);
            }
        }
        return result;
    }
};

