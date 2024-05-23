#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int knapsack(const vector<int> &weights, const vector<int> &values, int W)
{
  int n = weights.size();
  vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

  for (int i = 1; i <= n; ++i)
  {
    for (int w = 0; w <= W; ++w)
    {
      if (weights[i - 1] <= w)
      {
        dp[i][w] = max(dp[i - 1][w], dp[i - 1][w - weights[i - 1]] + values[i - 1]);
      }
      else
      {
        dp[i][w] = dp[i - 1][w];
      }
    }
  }

  // Menampilkan langkah-langkah
  cout << "Langkah-langkah:" << endl;
  for (int i = 0; i <= n; ++i)
  {
    for (int w = 0; w <= W; ++w)
    {
      cout << dp[i][w] << " ";
    }
    cout << endl;
  }

  return dp[n][W];
}

// menampilkan rumus max(𝟐+(𝟖−𝟑),𝟎) 
for (int i = 1; i <= n; ++i)
{
  for (int w = 0; w <= W; ++w)
  {
    if (weights[i - 1] <= w)
    {
      dp[i][w] = max(dp[i - 1][w], dp[i - 1][w - weights[i - 1]] + values[i - 1]);
    }
    else
    {
      dp[i][w] = dp[i - 1][w];
    }
  }
} 

int main()
{
  vector<int> weights = {2, 3, 4, 5, 6, 7, 8};
  vector<int> values = {90, 30, 60, 70, 20, 80, 50};
  // int W = 15;
  int W = 10;   

  int maxValue = knapsack(weights, values, W);
  cout << "Nilai maksimum yang dapat diperoleh: " << maxValue << endl;

  return 0;
}