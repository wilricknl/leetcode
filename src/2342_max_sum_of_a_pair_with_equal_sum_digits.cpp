class Solution {
public:
    int maximumSum(vector<int>& nums) {
        std::unordered_map<int, int> sums;
        int answer = 0;

        for (int num : nums)
        {
            int sum = 0;
            int temp = num;
            while (temp)
            {
                sum += temp % 10;
                temp /= 10;
            }

            if (sums.contains(sum))
            {
                answer = std::max(answer, sums[sum] + num);
                if (num > sums[sum])
                {
                    sums[sum] = num;
                }
            }
            else
            {
                sums[sum] = num;
            }
        }

        return answer ? answer : -1;
    }
};

