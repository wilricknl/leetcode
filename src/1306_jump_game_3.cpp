class Solution {
public:
    bool canReach(vector<int>& arr, int start)
    {
        if (arr[start] == 0) return true;
    
        int n = arr.size();

        std::vector<char> seen(n, false);
        std::queue<int> q;
        q.push(start);
        seen[start] = true;

        while (!q.empty())
        {
            auto node = q.front();
            q.pop();

            int left = node - arr[node];
            if (left >= 0)
            {
                if (!seen[left])
                {
                    if (arr[left] == 0)
                    {
                        return true;
                    }
                    q.push(left);
                    seen[left] = true;
                }
            }

            int right = node + arr[node];
            if (right < n)
            {
                if (!seen[right])
                {
                    if (arr[right] == 0)
                    {
                        return true;
                    }

                    q.push(right);
                    seen[right] = true;
                }
            }
        }

        return false;
    }
};

