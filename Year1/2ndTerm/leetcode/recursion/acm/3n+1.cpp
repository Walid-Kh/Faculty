#include <bits/stdc++.h>
using namespace std;
int con(int n)
{
  if (n == 1)
    return 1;
  else if (n % 2)
    return 1 + con(3 * n + 1);
  else
    return 1 + con(n / 2);
}
int main()
{
  int n;
  cin >> n;
  int *i = new int[n], *j = new int[n];
  for (int k = 0; k < n; k++)
    cin >> i[k] >> j[k];
  for (int a = 0; a < n; a++)
  {
    int max = 0;
    for (int b = i[a]; b <= j[a]; b++)
    {
      int conb = con(b); 
      if (conb > max)
        max = conb;  
    }
    cout << i[a] << " " << j[a] << " " << max << endl; 
  }
}
// based upon the test 
// 1 10
// 100 200
// 201 210
// 900 1000
// the code works fine