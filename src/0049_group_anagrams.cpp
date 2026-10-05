class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::unordered_map<std::string, std::vector<std::string>> anagrams;
        for (const auto& str : strs)
        {
            auto copy = str;
            std::sort(copy.begin(), copy.end());
            anagrams[copy].push_back(str);
        }

        std::vector<std::vector<std::string>> answer;
        for (auto& [key, value] : anagrams)
        {
            answer.push_back(std::move(value));
        }

        return answer;
    }
};

