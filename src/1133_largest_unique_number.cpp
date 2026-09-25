class Solution {
public:
    int largestUniqueNumber(vector<int>& nums) {
        static int occurrences[2001]; // -1 means no occurrence
        std::fill(occurrences, occurrences + 2001, -1);
        
        int maxNumber = nums[0];
        for (int i = 0; i < nums.size(); ++i)
        {
            auto number = nums[i];
            if (occurrences[number] == -1)
                occurrences[number] = 1;
            else
                ++occurrences[number];
            maxNumber = std::max(maxNumber, number);
        }
        
        for (int i = maxNumber; maxNumber >= 0; --maxNumber)
        {
            if (occurrences[maxNumber] == 1)
                return maxNumber;
        }
        return -1;
    }
};

