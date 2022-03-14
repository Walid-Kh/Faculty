#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
  vector<vector<int>> dp;
  bool PredictTheWinner(vector<int> nums)
  {
    dp.resize(nums.size());
    int sum = 0;
    for (int i = 0; i < nums.size(); i++)
    {
      sum += nums[i];
      dp[i].resize(nums.size());
    }
    for (int i = 0; i < nums.size(); i++)
      for (int j = 0; j < nums.size(); j++)
        dp[i][j] = 0;
    go(nums, 0, nums.size() - 1);

    return dp[0][nums.size() - 1] >= 0;
  };
  int go(vector<int> nums, int start, int end, bool turn = 1)
  {
    int x;
    if (start == end)
    {
      x = nums[start];
      dp[start][end] = x;
    }
    else if (dp[start][end] != 0)
      x = dp[start][end];
    else
    {
      if (turn)
        x = max(go(nums, start + 1, end, !turn) + nums[start], go(nums, start, end - 1, !turn) + nums[end]);
      else
        x = min(go(nums, start + 1, end, !turn) - nums[start], go(nums, start, end - 1, !turn) - nums[end]);
      dp[start][end] = x;
    }
    return x; 
  }
};
int main()
{
  vector<int> nums = {1,5,2};
  Solution s;
  cout << s.PredictTheWinner(nums) << endl;

  return 0;
}