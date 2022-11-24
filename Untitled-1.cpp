#include <bits/stdc++.h>
using namespace std;

int knapsack(int W, vector<int> v, vector<int> w)
{
    int n = w.size();
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= W; j++)
        {

            dp[i][j] = dp[i - 1][j];
            if (w[i - 1] <= j)
                dp[i][j] = max(dp[i - 1][j], v[i - 1] + dp[i - 1][j - w[i - 1]]);
        }
    }
    return dp[n][W];
}

int main()
{
    int n, W;
    cin >> n >> W;
    vector<int> v(n, 0);
    vector<int> w(n, 0);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    for (int i = 0; i < n; i++)
        cin >> w[i];
    cout << knapsack(W, v, w);
    return 0;
}