class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        // initial state is target
        if ("0000" == target) return 0;

        std::vector<char> seen(10000, false);
        for (const auto& deadend : deadends)
        {
            int key = 
                    1000 * (deadend[0] - '0')
                    + 100 * (deadend[1] - '0')
                    + 10 * (deadend[2] - '0')
                    + 1 * (deadend[3] - '0');
            seen[key] = true;
        }

        // initial state "0000" is in deadends
        if (seen[0]) return -1;

        std::vector<std::vector<int>> directions{
            { 1, 0, 0 ,0 }, { -1, 0, 0 , 0},
            { 0, 1, 0, 0 }, { 0, -1, 0, 0 },
            { 0, 0 ,1, 0 }, { 0, 0 ,-1, 0 },
            { 0, 0 , 0, 1 }, { 0, 0 , 0, -1}
        };

        std::queue<std::string> q;
        q.push("0000");
        seen[0] = true;
        int distance = 1;
        while (!q.empty())
        {
            int qs = q.size();

            for (int i = 0; i < qs; ++i)
            {
                auto lock = q.front();
                q.pop();

                for (const auto& direction : directions)
                {
                    auto nextLock = lock;
                    for (int j = 0; j < 4; ++j)
                    {
                        char c = nextLock[j] + direction[j];
                        if (c < '0') c = '9';
                        if (c > '9') c = '0';
                        nextLock[j] = c;
                    }

                    if (nextLock == target)
                    {
                        return distance;
                    }

                    int key = 
                        1000 * (nextLock[0] - '0')
                        + 100 * (nextLock[1] - '0')
                        + 10 * (nextLock[2] - '0')
                        + 1 * (nextLock[3] - '0');
                    if (!seen[key])
                    {
                        q.push(nextLock);
                        seen[key] = true;
                    }
                }
            }
            ++distance;
        }

        return -1;
    }
};

