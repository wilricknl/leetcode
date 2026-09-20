class Solution {
public:
    int countElements(vector<int>& arr) {
        std::unordered_set<int> numbers(arr.begin(), arr.end());
        int total = 0;
        for (auto number : arr)
        {
            if (numbers.contains(number+1))
                ++total;
        }
        return total;
    }
};

