class Solution
{
public:
    int maximizeSweetness(vector<int>& sweetness, int k)
    {
        k = k + 1;
        int left = 1;
        int right = std::accumulate(sweetness.begin(), sweetness.end(), 0) / k;

        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (check(sweetness, mid, k))
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }

        return right;
    }

    bool check(std::vector<int>& sweetness, int minimumSweetness, int k)
    {
        int count = 0;
        int sectionTotal = 0;
        for (auto s : sweetness)
        {
            sectionTotal += s;
            if (sectionTotal >= minimumSweetness)
            {
                sectionTotal = 0;
                ++count;
            }
        }
        return count >= k;
    }
};

