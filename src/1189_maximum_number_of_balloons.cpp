class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int characterCount[26]{};
        for (char character : text)
        {
            ++characterCount[character - 'a'];
        }
        
        return std::min({characterCount[1], characterCount[0], characterCount['l' - 'a'] / 2, characterCount['o' - 'a'] / 2, characterCount['n' - 'a'] });
    }
};

