class Solution {
public:
    std::string processText(std::string s)
    {
        std::string result;
        for (char letter : s)
        {
            if (letter != '#')
            {
                result.push_back(letter);
            }
            else if (!result.empty())
            {
                result.pop_back();
            }
        }
        return result;
    }

    bool backspaceCompare(string s, string t) {
        return processText(s) == processText(t);
    }
};

