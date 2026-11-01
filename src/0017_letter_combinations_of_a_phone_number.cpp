class Solution {
public:
    std::string digitToLetters(char digit)
    {
        switch(digit)
        {
            case '2':
                return "abc";
            case '3':
                return "def";
            case '4':
                return "ghi";
            case '5':
                return "jkl";
            case '6':
                return "mno";
            case '7':
                return "pqrs";
            case '8':
                return "tuv";
            default:
                return "wxyz";
        }
    }

    void backtrack(
        std::vector<std::string>& answer,
        int index,
        std::string& digits)
    {
        if (index == digits.size())
        {
            answer.push_back(digits);
            return;
        }

        auto digit = digits[index];
        auto letters = digitToLetters(digit);
        for (auto letter : letters)
        {
            digits[index] = letter;
            backtrack(answer, index + 1, digits);
        }
        digits[index] = digit;
    }

    vector<string> letterCombinations(string digits) {
        std::vector<std::string> answer;
        std::string state;
        backtrack(answer, 0, digits);
        return answer;
    }
};

