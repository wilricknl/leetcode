class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList)
    {
        std::unordered_set<std::string> valid;
        for (const auto& word : wordList)
        {
            valid.insert(word);
        }

        if (!valid.contains(endWord))
        {
            return 0;
        }

        std::queue<std::string> q;
        q.push(beginWord);
        if (valid.contains(beginWord))
        {
            valid.erase(beginWord);
        }

        int steps = 1;
        while (!q.empty())
        {
            int qs = q.size();
            ++steps;

            for (int i = 0; i < qs; ++i)
            {
                auto word = q.front();
                q.pop();

                int wordLength = word.size();
                for (int letter = 0; letter < wordLength; ++letter)
                {
                    for (int j = 0; j < 26; ++j)
                    {
                        char newLetter = 'a' + j;
                        if (word[letter] == newLetter)
                        {
                            continue;
                        }

                        auto newWord = word;
                        newWord[letter] = newLetter;

                        if (!valid.contains(newWord))
                        {
                            continue;
                        }

                        if (endWord == newWord)
                        {
                            return steps;
                        }

                        valid.erase(newWord);
                        q.push(newWord);
                    }
                }
            }
        }

        return 0;    
    }
};

