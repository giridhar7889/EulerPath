class Solution
{
public:
    const static int N = 1e5, Mod = 1e5;
    int dp[N];
    int numSquares(int n)
    {
        for (int i = 0; i < N; i++)
        {
            dp[i] = Mod;
        }
        return minsquare(n);
    }
    int minsquare(int n)
    {
        if (n == 0 || n == 1 || n == 2 || n == 3)
        {
            return n;
        }

        if (dp[n] != Mod)
        {
            return dp[n];
        }
        for (int i = 1; i * i <= n; i++)
        {
            dp[n] = min(dp[n], 1 + minsquare(n - (i * i)));
        }
        return dp[n];
    }
};