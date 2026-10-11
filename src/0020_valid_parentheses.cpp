class Solution {
public:
    bool isValid(string s) {
        std::stack<char> characters;
        for (char letter : s)
        {
            char open = 0;
            switch (letter)
            {
                case ')': open = '('; break;
                case ']': open = '['; break;
                case '}': open = '{'; break;
            }

            if (open && !characters.empty() && characters.top() == open)
            {
                characters.pop();
            }
            else
            {
                characters.push(letter);
            }
        }

        return characters.empty();
    }
};

