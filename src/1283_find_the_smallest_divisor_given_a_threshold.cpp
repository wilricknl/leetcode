class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold)
    {
        int left = 1;
        int right = 1;
        for (auto num : nums)
        {
            right= std::max(right, num);
        }

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (check(nums, mid, threshold)) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return left;
    }

    bool check(vector<int>& nums, int divisor, int threshold) {
        int sum = 0;
        for (auto num : nums)
        {
            sum += (num + divisor  - 1) / divisor;
        }
        return sum <= threshold;
    }
};

