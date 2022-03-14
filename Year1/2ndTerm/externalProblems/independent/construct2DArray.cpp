#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
  vector<vector<int>> construct2DArray(vector<int> &original, int m, int n)
  {
    vector<vector<int>> res (m,vector<int>(n)); 
    if (original.size() == m*n)
    {
      int k = 0; 
      for (int i = 0; i < m; i++)
      {
        for (int j = 0; j < n; j++)
        {
          res[i][j] = original[k];
          k++; 
        }
      }
    return res; 
    }
    return {{}}; 
  }
};
int main()
{
  Solution s; 
  vector<int> x = {1,2};
  vector<vector<int>> res = s.construct2DArray(x,1,1);  
  for (int i = 0 ; i < res.size(); i++)
  {
    cout << "| " ;
    for (int j = 0; j < res[0].size(); j++)
    {
      cout << res[i][j] << " "; 
    }
    cout << "|" << endl ;
  } 
  return 0;
}