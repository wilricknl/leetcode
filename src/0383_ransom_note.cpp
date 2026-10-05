class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int ransomLetters[26]{};
        int magazineLetters[26]{};
        
        for (char letter : ransomNote)
        {
            ++ransomLetters[letter - 'a'];
        }
        
        for (char letter : magazine)
        {
            ++magazineLetters[letter - 'a'];
        }
        
        for (int i = 0; i < 26; ++i)
        {
            if (ransomLetters[i] > magazineLetters[i])
                return false;
        }
        
        return true;
    }
};

