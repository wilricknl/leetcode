class Solution {
public:

	int myAtoi(string s)
    {
	    int result = 0;
	    int sign = 1;

	    int i = 0;

	    // skip leading whitespace
	    for (; i < s.size() && isspace(s[i]); ++i);
	    if (i == s.size()) return result;

	    // check for sign
	    if (int c = s[i]; c == '-' || c == '+')
	    {
		    sign = s[i++] == '+' ? 1 : -1;
	    }

	    // skip leading 0s
	    for (; i < s.size() && s[i] == '0'; ++i);

        // compute result
        while (i < s.size() && isdigit(s[i]))
	    {
            auto value = s[i++] - '0';
            if (result > (std::numeric_limits<int>::max() - value)/10)
                return std::numeric_limits<int>::max();
            if (result < (std::numeric_limits<int>::min() + value) / 10)
                return std::numeric_limits<int>::min();
            result = result * 10 + (value * sign);
	    }

        return result;
	}
};
