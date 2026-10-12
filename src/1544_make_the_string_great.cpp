class Solution {
public:
    string makeGood(string s) {
        string result;
        for (char letter : s)
        {
            if (!result.empty() && result.back() != letter && std::tolower(result.back()) == std::tolower(letter))
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

