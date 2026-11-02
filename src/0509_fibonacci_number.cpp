class Solution
{
public:
    int fib(int n)
    {
        static int memoization[31];
        memoization[0] = 0;
        memoization[1] = 1;
        for (int i = 2; i <= n; ++i)
        {
            memoization[i] = memoization[i - 2] + memoization[i - 1];
        }
        return memoization[n];
    }
};

