class Solution
{
public:
    int minSpeedOnTime(vector<int>& dist, double hour)
    {
        if ((size_t)std::ceil(hour) < dist.size()) return -1;
        
        int left = 1;
        int right = 10'000'000;

        while (left <= right)
        {
            int middle = left + (right - left) / 2;
            if (check(dist, middle, hour))
            {
                right = middle - 1;
            }
            else
            {
                left = middle + 1;
            }
        }

        return left;
    }

    bool check(vector<int>& dist, int speed, double hour)
    {
        int total = 0;
        for (int i = 0; i < dist.size() - 1; ++i)
        {
            total += (dist[i] + speed - 1) / speed;
        }

        double time = total + static_cast<double>(dist.back()) / speed;
        return time <= hour;
    }
};

