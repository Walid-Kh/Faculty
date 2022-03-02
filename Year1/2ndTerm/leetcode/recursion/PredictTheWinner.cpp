#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
  bool PredictTheWinner(vector<int> &nums)
  {
    // due Dynamic programming
    vector<vector<int>> dp (nums.size(),vector<int>(2)); 
  }
  
};
int main()
{
  vector<int> nums = {1,5,233,7}; 
  Solution s; 
  cout << s.PredictTheWinner(nums) << endl; 
  
  return 0;
}