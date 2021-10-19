class Solution
{
public:
    int change(int amount, vector<int> &coins)
    {
        int n = coins.size();
        int dp[amount + 1];
        dp[0] = 1;
        for (int x = 1; x <= amount; x++)
        {
            dp[x] = 0;
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 1; j <= amount; j++)
            {
                int rem = j - coins[i];
                if (rem >= 0)
                {

                    dp[j] = dp[j] + dp[rem];
                }
            }
        }
        return dp[amount];
    }
};