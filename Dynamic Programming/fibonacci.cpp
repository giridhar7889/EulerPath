#include <iostream>
#include <vector>
using namespace std;

const int N = 1e5;
int dp[N];

int fib(int n)
{
    if (n == 1 || n == 0)
    {
        return 0;
    }
    if (n == 2)
    {
        return 1;
    }
    if (dp[n] != -1)
    {
        return dp[n];
    }
    return dp[n] = fib(n - 1) + fib(n - 2);
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < N; i++)
    {
        dp[i] = -1;
    }
    cout << fib(n);
}