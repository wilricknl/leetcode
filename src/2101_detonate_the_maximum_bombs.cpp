class Solution {
public:
    int bfs(
        vector<vector<int>>& bombs,
        vector<char>& seen,
        int start)
    {
        queue<int> q;

        q.push(start);
        seen[start] = true;

        int n = bombs.size();
        int answer = 1;

        while (!q.empty())
        {
            auto bomb = q.front();
            const auto& bomb1 = bombs[bomb];
            q.pop();

            for (int i = 0; i < n; ++i)
            {
                const auto& bomb2 = bombs[i];

                long long dx = 1LL * bomb2[0] - bomb1[0];
                long long dy = 1LL * bomb2[1] - bomb1[1];
                long long r = bomb1[2];

                if (!seen[i] && dx * dx + dy * dy <= r * r)
                {
                    seen[i] = true;
                    ++answer;
                    q.push(i);
                }
            }
        }

        return answer;
    }

    int maximumDetonation(vector<vector<int>>& bombs)
    {
        int n = bombs.size();
        int answer = 0;

        for (int i = 0; i < n; ++i)
        {
            vector<char> seen(n, false);
            answer = max(answer, bfs(bombs, seen, i));
        }

        return answer;
    }
};

