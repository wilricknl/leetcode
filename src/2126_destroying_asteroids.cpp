class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids)
    {
        std::sort(asteroids.begin(), asteroids.end());
        long long m = mass;
        for (auto asteroid : asteroids)
        {
            if (asteroid > m) return false;
            m += asteroid;
        }

        return true;
    }
};

