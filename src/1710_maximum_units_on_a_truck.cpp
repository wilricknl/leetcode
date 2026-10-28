class Solution
{
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize)
    {
        for (auto& boxType : boxTypes)
            std::swap(boxType[0], boxType[1]);
        std::sort(boxTypes.begin(), boxTypes.end());
        
        int total = 0;
        for (int i = boxTypes.size() - 1; i >= 0 && truckSize > 0; --i)
        {
            auto boxSize = boxTypes[i][1];
            if (boxSize <= truckSize)
            {
                total += boxSize * boxTypes[i][0];
                truckSize -= boxSize;
            }
            else
            {
                total += truckSize * boxTypes[i][0];
                truckSize = 0;
            }
        }        
        return total;
    }
};

