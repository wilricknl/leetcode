class Solution {
public:
    int minSetSize(vector<int>& arr)
    {
        std::sort(arr.begin(), arr.end());
        int n = arr.size();
        int half_n = (int)(std::ceil(n / 2.0f));
        
        std::priority_queue<int> pq;
        int previous = arr[0];
        int count = 1;
        for (int i = 1; i < n; ++i)
        {
            if (arr[i] == previous)
            {
                ++count;
            }
            else
            {
                pq.push(count);
                previous = arr[i];
                count = 1;
            }
        }
        pq.push(count);
        
        int answer = 0;
        while (!pq.empty() && n > half_n)
        {
            auto value = pq.top();
            pq.pop();
            n -= value;
            ++answer;
        }
        return answer;
    }
};

