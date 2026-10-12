class Solution {
public:
    void processToken(std::string& result, std::string& token)
    {
        if (token == ".")
        {
            result.pop_back();
        }
        else if (token == "..")
        {
            int slashes = 0;
            while (result.size() && slashes < 2)
            {
                if (result.back() == '/')
                    ++slashes;
                result.pop_back();
            }
            // above deletes 1 too many slashes
            result.push_back('/');
        }
        else
        {
            result.push_back('/');
        }
        token = "";
    }

    string simplifyPath(string path)
    {
        std::string result{'/'};
        std::string token;

        for (char letter : path)
        {
            if (letter != '/')
            {
                result.push_back(letter);
                token.push_back(letter);
            }
            else if (result.back() != letter) // ignore double slashes
            {
                processToken(result, token);
            }
        }

        // process last token
        if (!token.empty())
            processToken(result, token);
        // remove trailing slash
        if (result.size() > 1 && result.back() == '/')
            result.pop_back();

        return result;
    }
};

