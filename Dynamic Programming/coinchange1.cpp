class Solution
{
public:
    int coinChange(vector<int> &coins, int amount)
    {
        int n = coins.size();
        int dp[amount + 1];
        for (int a = 0; a <= amount; a++)
        {
            dp[a] = 1e5;
        }
        dp[0] = 0;
        for (int i = 0; i <= amount; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i - coins[j] >= 0)
                {
                    dp[i] = min(dp[i], 1 + dp[i - coins[j]]);
                }
            }
        }
        if (dp[amount] != 1e5)
        {
            return dp[amount];
        }
        else
        {
            return -1;
        }
    }
};