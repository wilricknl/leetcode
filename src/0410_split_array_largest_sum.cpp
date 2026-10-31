class Solution {
public:
    int splitArray(vector<int>& nums, int k)
    {
        // take maximum element as minimum size, because we can't create subarrays smaller
        // than the size of maximum element
        int left = *std::max_element(nums.begin(), nums.end());

        // use sum of all elements as maximum
        int right = std::accumulate(nums.begin(), nums.end(), 0);

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (check(nums, mid, k)) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return left;
    }

    bool check(std::vector<int>& nums, int target, int k)
    {
        int count = 0;
        int sectionTotal = 0;
        for (int num : nums)
        {
            // check if adding this element would exceed subarray size
            if (sectionTotal + num > target)
            {
                ++count;
                sectionTotal = 0;
            }
            sectionTotal += num;
        }
        return count < k;
    }
};

