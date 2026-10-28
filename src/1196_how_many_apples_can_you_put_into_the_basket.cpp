class Solution
{
public:
    int maxNumberOfApples(vector<int>& weight) {
        std::sort(weight.begin(), weight.end());
        
        int w = 5000;
        int count = 0;
        for (int i = 0; i < weight.size(); ++i)
        {
            if (weight[i] > w)
                break;
            w -= weight[i];
            ++count;
        }

        return count;
    }
};

