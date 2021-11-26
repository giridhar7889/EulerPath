#include <iostream>
#include <vector>
using namespace std;

int opt(int i, int j, vector<int> &keys, vector<int> &freq, vector<vector<int>> &dp)
{
    if (j < i)
    {
        return 0;
    }
    if (i == j)
    {
        return freq[i];
    }
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }
    int sum = 0;
    int min = 1e5;
    for (int s = i; s <= j; s++)
    {
        sum = sum + freq[s];
    }
    for (int r = i; r <= j; r++)
    {
        int cost = opt(i, r - 1, keys, freq, dp) + opt(r + 1, j, keys, freq, dp);
        if (cost < min)
        {
            min = cost;
        }
    }
    return dp[i][j] = sum + min;
}

int main()
{
    int n;
    cin >> n;
    vector<int> keys;
    vector<int> freq;
    for (int i = 0; i < n; i++)
    {
        int k, f;
        cin >> k >> f;
        keys.push_back(k);
        freq.push_back(f);
    }
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
    cout << opt(0, n - 1, keys, freq, dp);
}