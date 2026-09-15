class Solution {
public:
    int reverse(int x) {
        int result = 0;

        for (; x != 0; x /= 10)
        {
            int value = x % 10;
            if (result > std::numeric_limits<int>::max() / 10 ||
                result < std::numeric_limits<int>::min() / 10)
                return 0;

            result = result * 10 + value;
        }
        
        return result;
    }
};
