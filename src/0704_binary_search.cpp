class Solution
{
public:
    int search(vector<int>& nums, int target)
    {
        int left = 0;
        int right = nums.size() - 1;

        while (left <= right)
        {
            int middle = (left + right) / 2;
            int value = nums[middle];
            if (value == target)
            {
                return middle;
            }
            else if (value < target)
            {
                left = middle + 1;
            }
            else if (value > target)
            {
                right = middle - 1;   
            }
        }
        return -1;
    }
};

